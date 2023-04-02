/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:46:31 by ekadiri           #+#    #+#             */
/*   Updated: 2023/04/01 18:34:19 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	give_types(t_token *t)
{
	while (t->next)
	{
		if (t->content)
			t->type = get_type(t->content);
		t = t->next;
	}
	t = tokenfirst(t);
	while (t->next)
	{
		if (!type_is_sep(t->next->type) && t->next->type != END)
		{
			if (t->type == GREAT)
				t->next->type = A_GREAT;
			else if (t->type == LESS)
				t->next->type = A_LESS;
			else if (t->type == D_GREAT)
				t->next->type = A_DGREAT;
			else if (t->type == D_LESS)
				t->next->type = A_DLESS;
		}
		t = t->next;
	}
}
