/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:23:58 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/01 22:57:43 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_expand(t_exp *exp)
{
	t_exp	*ptr;

	ptr = exp;
	while (exp)
	{
		printf("%d : %s len : %zu\n", exp->index, exp->var, ft_strlen(exp->var));
		exp = exp->next;
	}
	exp = ptr;
}

char	*expand(char *s, t_env *env)
{
	int		i;
	int		j;
	int		k;
	char	*ret;
	char	*to_copy;
	t_exp	*exp;
	t_exp	*ptr;

	exp = init_expand(s);
	if (!exp)
		return (s);
	ptr = exp;
	ret = malloc(memory_needed(s, env, exp));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	if (!exp)
		return (s);
	while (exp)
	{
		while (s[i] && i < exp->index)
			ret[j++] = s[i++];
		to_copy = get_var(exp->var, env);
		if (to_copy)
		{
			k = 0;
			while (to_copy[k])
				ret[j++] = to_copy[k++];
			free(to_copy);
		}
		i += ft_strlen(exp->var) + 1;
		exp = exp->next;
	}
	while (s[i])
		ret[j++] = s[i++];
	expclear(ptr);
	ret[j] = 0;
	return (ret);
}
