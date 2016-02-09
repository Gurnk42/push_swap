/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:32:38 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/09 19:10:19 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_disp_push_a(t_env *e)
{
	if (*(e->op) != '\0')
		e->op = ft_strjoin_free(e->op, ft_strdup(" "));
	e->op = ft_strjoin_free(e->op, ft_strdup("pa"));
	ft_push_a(e);
	if (e->flag_v == 1)
		ft_stacks_state(e);
}

void	ft_disp_push_b(t_env *e)
{
	if (*(e->op) != '\0')
		e->op = ft_strjoin_free(e->op, ft_strdup(" "));
	e->op = ft_strjoin_free(e->op, ft_strdup("pb"));
	ft_push_b(e);
	if (e->flag_v == 1)
		ft_stacks_state(e);
}

void	ft_push_a(t_env *e)
{
	void	*tmp;

	if (e->len_b >= 1)
	{
		e->len_a++;
		e->len_b--;
		ft_lstadd(&(e->a), ft_lstnew(e->b->content, sizeof(tmp)));
		tmp = e->b->next;
		ft_memdel((void **)&(e->b->content));
		ft_memdel((void **)&(e->b));
		e->b = tmp;
	}
}

void	ft_push_b(t_env *e)
{
	void	*tmp;

	if (e->len_a >= 1)
	{
		e->len_b++;
		e->len_a--;
		ft_lstadd(&(e->b), ft_lstnew(e->a->content, sizeof(tmp)));
		tmp = e->a->next;
		ft_memdel((void **)&(e->a->content));
		ft_memdel((void **)&(e->a));
		e->a = tmp;
	}
}
