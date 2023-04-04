/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:09:51 by mvicedo           #+#    #+#             */
/*   Updated: 2023/04/02 15:44:44 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	var_name_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int ft_is_new_var(t_env *env_lst, char *str, int i_equal)
{
	t_env *ptr;
	int		len;

	ptr = env_lst;
	while (ptr)
	{
		len = ft_is_equal(ptr->env_str);
		if (!ft_strncmp(ptr->env_str, str, i_equal) && len == i_equal)
			return (0);
		ptr = (ptr)->next;
	}
	return (1);
}

void	ft_update_var(t_env *env_lst, char *str, int i_equal)
{
	t_env	*ptr;
	int		len;
	
	ptr = env_lst;
	while (ptr)
	{
		len = ft_is_equal(ptr->env_str);
		if (!ft_strncmp(ptr->env_str, str, i_equal) && len == i_equal)
		{
			free(ptr->env_str);
			ptr->env_str = ft_strdup(str);
		}
		ptr = ptr->next;
	}
	
}

// int	get_content_len(char *str, int i_equal)
// {
// 	int count;

// 	count = 0;
// 	while (str[i_equal])
// 	{
// 		i_equal++;
// 		count++;
// 	}
// 	return (count);
// }

// char	*ft_join_content(t_env *env_lst, char *var_name, int i_equal, char *content)
// {
// 	t_env	*ptr;
	
// 	ptr = env_lst;
// 	printf("%s\n", var_name);
// 	while (ptr)
// 	{
// 		if (!ft_strncmp(ptr->env_str, var_name, i_equal))
// 		{
// 			ptr->env_str = ft_strjoin(ptr->env_str, content);
// 			return (ptr->env_str);
// 		}
// 		ptr = ptr->next;
// 	}
// 	return (NULL);
// }

// char *ft_join_var(t_env *env_lst, char *str, int i_equal)
// {
// 	char 	*var_name;
// 	char 	*var_content;
// 	char	*var_line;
// 	int		len;

// 	len = get_content_len(str, i_equal + 1);
// 	var_name = ft_substr(str, 0, (i_equal - 1));
// 	printf("%s\n", var_name);
// 	var_content = ft_substr(str, (i_equal + 1), len);
// 	printf("%s\n", var_content);
// 	free(str);
// 	if (ft_is_new_var(env_lst, var_name, i_equal))
// 		var_line = ft_strjoin(var_name, var_content);
// 	else
// 	{
// 		//var_line = ft_strjoin(var_name, var_content);
// 		var_line = ft_join_content(env_lst, var_name, i_equal + 1, var_content);
// 	}
// 	free(var_name);
// 	free(var_content);
// 	return (var_line);
// }

