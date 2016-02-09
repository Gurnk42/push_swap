/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:31:10 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/09 21:22:44 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_rot_both(t_env *e)
{
	ft_rot_stack('a', e);
	ft_rot_stack('b', e);
}

t_list		*ft_get_last(t_list *lst, size_t len)
{
	if (len >= 1)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void		ft_disp_rot_a(t_env *e)
{
	ft_rot_stack('a', e);
	if (*(e->op) != '\0')
		e->op = ft_strjoin_free(e->op, ft_strdup(" "));
	e->op = ft_strjoin_free(e->op, ft_strdup("ra"));
	if (e->flag_v == 1)
		ft_stacks_state(e);
}

static void	ft_rot_select_stack(t_list **lst, size_t *len, char stack, t_env *e)
{
	if (stack == 'a')
	{
		*lst = e->a;
		*len = e->len_a;
	}
	else
	{
		*lst = e->b;
		*len = e->len_b;
	}
}

void		ft_rot_stack(char stack, t_env *e)
{
	void	*first;
	t_list	*lst;
	size_t	len;

	e->nb_op++;
	ft_rot_select_stack(&lst, &len, stack, e);
	if (len >= 2)
	{
		first = lst->content;
		while (lst)
		{
			if (lst->next != NULL)
				lst->content = lst->next->content;
			else
				lst->content = first;
			lst = lst->next;
		}
	}
}
