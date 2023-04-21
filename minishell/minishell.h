/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:34:08 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/20 23:25:18 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//Includes
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
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
# include <limits.h>

# define ADD 1
# define ERR_INFILE "Infile"
# define ERR_HEREDOC "heredoc"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe Failed"
# define ERR_FORK "fork failed\n"

extern int	g_exit_code;

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
	int				status;
	pid_t			pid;
	pid_t			pid_one;
	char			*cmd_path;
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

typedef struct s_here
{
	char			*delim;
	int				pipe[2];
	struct s_here	*next;
}	t_here;

typedef struct s_data
{
	char	**env_cpy;
	t_cmd	*cmd;
	t_token	*t;
	t_env	*env_lst;
	t_here	*here;
	int		nbr_here;
	int		pfd[2];
	int		prev_pipe;
	int		nbr_cmd;
	int		nbr_pipe;
	int		exit_status;
	int		fd;
	int		fd2;
	int		fd_out;
	int		fd_in;
}	t_data;

void		free_all(t_cmd *cmd, t_token *token);

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
int			ft_putstr_fd(char const *s, int fd);
int			ft_putendl_fd(char const *s, int fd);
char		*ft_strnstr(char const *str, char const *to_find, size_t len);
int			ft_strcmp(char *s1, char *s2);
int			ft_isdigit(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_itoa(int n);
int			ft_putchar_fd(char c, int fd);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_printf(const char *s, ...);
void		ft_bzero(void *const s, size_t const size);

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
void		expand_func_3(char *s, int *i);

//STR
char		*remove_quotes(char *str);
int			skip_and_copy(char *str, char *ret, int *i, int *j);
void		skip_spaces(char *str, int *i, int *j);
char		*remove_spaces(char *s);
int			spaces_to_add(char *s);
int			space_func(char *s, char *ret, int *i, int *j);
char		*add_space(char *s);
char		*new_str(char *str, t_env *env);
int			is_space(char c);

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
void		quote(t_token *t);

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

//HEREDOC
t_here		*herenew(void);
void		handle_heredoc(t_cmd *cmd, t_data *data);
t_here		*herelast(t_here *here);
void		hereclear(t_here *here);
void		hereadd_back(t_here **lst, t_here *new);
t_here		*init_here(int n);

int			ft_count_hd(t_cmd *cmd);
void		get_delims_str(t_cmd *cmd, t_data *data);
void		delims_continue(t_cmd *cmd, t_data *data, int *index);

//EXEC
void		exit_free(t_data *data, t_cmd *cmd, int ret);
int			get_format_code(char *arg, int *flag);
void		dupnclose(int fd, int fd2);
int			exec_cmd(t_cmd *cmd_exec, t_data *data);
int			exec_pipe(t_cmd *cmd_exec, t_data *data);
void		ft_close_and_wait(t_data *data, t_cmd *tmp, int i);
void		exec_one_builtin(t_cmd *cmd_exec, t_data *data);
int			exec_one_cmd(t_cmd *cmd_exec, t_data *data);
int			search_and_execve(t_cmd *cmd_exec, t_data *data);
int			execve_path(t_cmd *cmd_exec, t_data *data);
char		*get_cmd(char *cmd, char **envp);
char		**ft_get_path(char **env);
void		execve_error(t_cmd *cmd_exec, int boolean);
int			execute_child(t_cmd *cmd_exec, t_data *data);
void		free_exeve(t_data *data, t_cmd *cmd_exec);
void		dup_fds(t_data *data, t_cmd *cmd_exec, int i);
void		close_fd(t_data *data, t_cmd *cmd_exec);
void		ft_close(t_data *data, t_cmd *cmd_exec);
void		ft_close_fd(t_cmd *cmd_exec);
char		**pass_env_list_to_tab(t_env *env_lst);
int			ft_free_pipes(t_data *data, int n);
int			verif(t_cmd *cmd_exec, t_data *data);
void		*ft_free(void **ptr);
void		free_exec(t_data *data, t_cmd *cmd);
int			get_result(t_data *data, t_cmd *cmd_exec, int result);
void		redir_fd(int *fd, t_cmd *tmp, t_data *data);
void		redir_fd_bt(int *fd, t_cmd *tmp, t_data *data);
void		error_fd(t_token *token, t_cmd *cmd, t_data *data);
int			error_fd_bt(t_token *token, t_cmd *cmd, t_data *data);
int			openfiles_bt(t_cmd *cmd, t_data *data);
void		openfiles(t_cmd *cmd, t_data *data);
int			heredoc_pipe(t_here *here, t_data *data, char *str);

//BUILTINS
int			is_builtin(char **cmd);
int			ft_built(t_data *mini, char **cmd, t_cmd *cmd_exec);
int			ft_echo(char **cmd, int len);
int			ft_export_var(t_env *env_lst, char *str);
int			ft_check_input(char *str);
int			export_msg(char *str);
void		ft_update_var(t_env *env_lst, char *str, int i_equal);
int			ft_is_new_var(t_env *env_lst, char *str, int i_equal);
int			var_name_len(char *str);
int			ft_export(t_cmd *cmd_exec, t_env *env_lst, int len);
void		ft_print_export(t_env **env_lst);
int			ft_is_equal(char *str);
int			ft_cd(char **cmd, t_env *env_lst);
void		ft_change_pwd(t_env *env_lst);
void		ft_change_oldpwd(t_env *env_lst, char *path);
int			ft_env(t_env *env_lst, int len);
int			ft_print_env(t_env *env_lst);
int			ft_pwd(void);
int			ft_unset(t_cmd *cmd_exec, t_env **env_lst, int len);
void		clear_var(t_env **env_list, char *str);
int			check_unset_input(char *str);
int			unset_msg(char *str);
int			ft_exit(t_data *data, char **cmd, t_cmd *exec_cmd);

//UTILS
void		init_struct(t_data *data, char **env);
void		exit_shell(t_data *data, t_cmd *cmd, int code);
void		antislash(int sig);
void		ctrlc(int sig);
void		ctrlc2(int sig);
t_data		*starton(void);

#endif
