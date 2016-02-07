/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:31:10 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 14:37:20 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot_both(t_env *e)
{
	ft_rot_stack('a', e);
	ft_rot_stack('b', e);
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
