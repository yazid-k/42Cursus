/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/01 21:47:33 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//Includes
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <aio.h>

typedef enum e_type{
	NONE,
	ARG,
	GREAT,
	D_GREAT,
	LESS,
	D_LESS,
	A_LESS,
	A_DLESS,
	A_GREAT,
	A_DGREAT,
	PIPE,
	D_PIPE,
	START,
	END
}	t_type;

typedef struct s_token
{
	char			*content;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_cmd
{
	char			*cmd;
	char			**cmd_arg;
	int				fd_in;
	int				fd_out;
	t_token			*token;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_env
{
	char			*env_str;
	struct s_env	*next;
}	t_env;

typedef struct s_exp
{
	char			*var;
	int				index;
	struct s_exp	*next;
}	t_exp;

//LIBFT
int			ft_isalnum(int c);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
char		*get_next_line(int fd);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

//EXPAND
void		lst_manager(t_env **env_lst, char *env_str);
void		free_lst(t_env **env_lst);
t_env		*ft_init_env(char **env);
t_exp		*expnew(char *content, int index);
t_exp		*explast(t_exp *exp);
void		expclear(t_exp *exp);
void		expadd_back(t_exp **lst, t_exp *new);
char		*get_var(char *str, t_env *env);
int			get_var_len(char *str, t_env *env);
int			env_char(char c);
int			memory_needed(char *str, t_env *env, t_exp *exp);
t_exp		*init_expand(char *s);
void		print_expand(t_exp *exp);
char		*expand(char *s, t_env *env);

//STR
char		*remove_quotes(char *str);
int			skip_and_copy(char *str, char *ret, int *i, int *j);
void		skip_spaces(char *str, int *i, int *j);
char		*remove_spaces(char *s);
int			spaces_to_add(char *s);
int			space_func(char *s, char *ret, int *i, int *j);
char		*add_space(char *s);
char		*new_str(char *str, t_env *env);

//TOKEN
void		tokenadd_back(t_token **lst, t_token *new);
int			tokensize(t_token *lst);
t_token		*tokennew(char *content, t_type type);
void		tokenclear(t_token *lst);
t_token		*tokenlast(t_token *lst);
t_token		*tokenfirst(t_token *lst);
void		print_token(t_token	*token);
t_type		get_type(char *s);
t_token		*init_tokens(char *s);
int			is_sep(t_type type);
void		give_types(t_token *t);
int			type_is_sep(t_type type);

//CMD
void		cmdadd_back(t_cmd **lst, t_cmd *new);
int			cmdsize(t_cmd *lst);
t_cmd		*cmdnew(char *content, t_token *token);
void		cmdclear(t_cmd *lst);
t_cmd		*cmdlast(t_cmd *lst);
t_cmd		*cmdfirst(t_cmd *lst);
char		*get_cmd_str(t_token *token);
t_token		*sub_token(t_token *token, int start, int size);
void		print_cmd(t_cmd *cmd);
t_token		*create_token_cmd(t_token *token, int i);
void		arr_func(t_cmd *cmd, int *i, char **arr);
char		**char_arr(t_cmd *cmd);
t_cmd		*create_cmd(t_token *token, int i);
t_cmd		*create_all_cmd(t_token *t);
int			output(t_cmd *cmd);
int			input(t_cmd *cmd);
int			give_fd(t_cmd *cmd);

//PARSING
void		free_tab(void **tab);
int			skip_quotes(char const *s, int *i);
int			is_cmd(char *cmd);
int			closed_quotes(char *s);
int			max(int a, int b);
void		print_error(char *err);
int			parse_pipes(t_cmd *cmd);
int			parse_redirections(t_cmd *cmd);
int			token_is_redir(t_token *token);
int			err_redir(t_token *token);
int			parse(t_cmd *cmd);

#endif
