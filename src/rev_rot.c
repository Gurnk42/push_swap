/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:19:42 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/10 19:18:18 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_rev_rot_both(t_env *e)
{
	ft_rev_rot_stack('a', e);
	ft_rev_rot_stack('b', e);
}

void			ft_disp_rev_rot_a(t_env *e)
{
	ft_rev_rot_stack('a', e);
	if (*(e->op) != '\0')
		e->op = ft_strjoin_free(e->op, ft_strdup(" "));
	e->op = ft_strjoin_free(e->op, ft_strdup("rra"));
	if (e->flag_v == 1)
		ft_stacks_state(e);
}

static t_list	**ft_rev_rot_select_stack(char stack, size_t *len, t_env *e)
{
	t_list	**lst;

	if (stack == 'a')
	{
		lst = &(e->a);
		*len = e->len_a;
	}
	else
	{
		lst = &(e->b);
		*len = e->len_b;
	}
	return (lst);
}

void			ft_rev_rot_stack(char stack, t_env *e)
{
	t_list	*beg;
	t_list	*tmp;
	t_list	*last;
	t_list	**lst;
	size_t	len;

	e->nb_op++;
	lst = NULL;
	beg = NULL;
	lst = ft_rev_rot_select_stack(stack, &len, e);
	if (len >= 2)
	{
		last = ft_get_last(*lst, stack);
		ft_lstadd(lst, ft_lstnew(last->content, sizeof(*last)));
		beg = *lst;
		while ((*lst)->next != NULL)
		{
			tmp = *lst;
			(*lst) = (*lst)->next;
		}
		ft_memdel((void **)(&((*lst)->content)));
		ft_memdel((void **)(lst));
		tmp->next = NULL;
	}
	*lst = beg;
}
