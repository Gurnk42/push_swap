/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 14:29:38 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/09 18:33:34 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_both(t_env *e)
{
	ft_swap_stack('a', e);
	ft_swap_stack('b', e);
}

void	ft_disp_swap_a(t_env *e)
{
	ft_swap_stack('a', e);
	if (*(e->op) != '\0')
		e->op = ft_strjoin_free(e->op, ft_strdup(" "));
	e->op = ft_strjoin_free(e->op, ft_strdup("sa"));
	if (e->flag_v == 1)
		ft_stacks_state(e);
}

void	ft_swap_stack(char stack, t_env *e)
{
	void	*tmp;
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
		tmp = lst->content;
		lst->content = lst->next->content;
		lst->next->content = tmp;
	}
}
