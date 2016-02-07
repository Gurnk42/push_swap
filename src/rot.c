/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:31:10 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 19:07:58 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_rot_both(t_env *e)
{
	ft_rot_stack('a', e);
	ft_rot_stack('b', e);
}

void	ft_rev_rot_both(t_env *e)
{
	ft_rev_rot_stack('a', e);
	ft_rev_rot_stack('b', e);
}

static t_list	*ft_get_last(t_list *lst, size_t len)
{
	if (len >= 1)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	ft_rev_rot_stack(char stack, t_env *e)
{
	t_list	*last;
	t_list	**lst;
	t_list	*begin;
	size_t	len;

	begin = NULL;
	lst = NULL;
	if (stack  == 'a')
	{
		lst = &(e->a);
		len = e->len_a;
	}
	else
	{
		lst = &(e->b);
		len = e->len_b;
	}
	if (len >= 2)
	{
		begin = *lst;
		last = ft_get_last(*lst, len);
		*((int *)(*lst)->content) = 24;
		*(int *)last->content = 42;
		ft_lstadd(lst, ft_lstnew(last->content, sizeof(*last)));
		//while ((*lst) != NULL)
		//	(*lst) = (*lst)->next;
		//ft_memdel((void **)(lst));
	}
	*lst = begin;
}

void	ft_rot_stack(char stack, t_env *e)
{
	void	*first;
	t_list	*lst;
	size_t	len;

	if (stack  == 'a')
	{
		lst = e->a;
		len = e->len_a;
	}
	else
	{
		lst = e->b;
		len = e->len_b;
	}
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
