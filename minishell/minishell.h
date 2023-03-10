/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/03/08 19:34:14 by ekadiri          ###   ########.fr       */
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
	t_token			*token;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

//LIBFT
double		ft_atof(char *str);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char const *s1, char const *s2, size_t n);
char		*ft_strnstr(char const *str, char const *to_find, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strtrim(char const *s, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*TOKEN FUNCS*/
void		tokenadd_back(t_token **lst, t_token *new);
void		tokenadd_front(t_token **lst, t_token *new);
void		tokenclear(t_token *lst);
t_token		*tokenlast(t_token *lst);
t_token		*tokennew(char *content, t_type type);
int			tokensize(t_token *lst);
t_token		*tokenfirst(t_token *lst);
void		print_token(t_token	*token);
int			get_token_size(char *s);
int			sep_size(char *s, int *i);
int			get_token_size_2(char *s);
int			get_token_count(char *s);
t_token		*create_token(char *s);
t_token		*create_all_tokens(char *s);
t_type		get_type(char *s);
int			type_is_sep(t_type type);
void		give_types(t_token *t);
void		trim_tokens(t_token *token);
t_token		*init_tokens(char *s);

/*CMD FUNCS*/
void		cmdadd_back(t_cmd **lst, t_cmd *new);
void		cmdadd_front(t_cmd **lst, t_cmd *new);
int			cmdsize(t_cmd *lst);
t_cmd		*cmdnew(char *content, t_token *token);
void		cmdclear(t_cmd *lst);
t_cmd		*cmdlast(t_cmd *lst);
t_cmd		*cmdfirst(t_cmd *lst);
char		*get_cmd_str(t_token *token);
t_token		*sub_token(t_token *token, int start, int size);;
void		print_cmd(t_cmd *cmd);
t_token		*create_token_cmd(t_token *token);
t_cmd		*create_cmd(t_token *token);
t_cmd		*create_all_cmd(t_token *t);

//Parsing
void		free_tab(void **tab);
void		skip_quotes(char *s, int *i);
int			is_cmd(char *cmd);
int			closed_quotes(char *s);
int			count_pipe(char *s);

#endif
