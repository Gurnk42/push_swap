/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:52:59 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/10 00:30:48 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_core_2(int *min_pos, t_env *e)
{
	int	i;

	i = 0;
	if (*min_pos == 1)
	{
		ft_disp_swap_a(e);
		i++;
	}
	else if (*min_pos <= (int)e->len_a / 2)
		while (i++ < *min_pos)
			ft_disp_rot_a(e);
	else
		while (i < (int)(e->len_a - *min_pos))
		{
			ft_disp_rev_rot_a(e);
			i++;
		}
	if (ft_is_sort(e->a, e->len_a) != 1)
		ft_disp_push_b(e);
}

static int	ft_sort_core(int *min_pos, int *ret, t_env *e)
{
	if ((*ret = ft_is_sort(e->a, e->len_a)) == 1)
	{
		while (e->len_b > 0)
			ft_disp_push_a(e);
		return (-1);
	}
	else if (*ret == 2)
	{
		ft_disp_rev_rot_a(e);
		ft_disp_rev_rot_a(e);
		ft_disp_swap_a(e);
		ft_disp_rot_a(e);
		ft_disp_rot_a(e);
		return (0);
	}
	ft_sort_core_2(min_pos, e);
	return (1);
}

void		ft_sort_stack(t_env *e)
{
	t_list	*lst;
	int		min_pos;
	int		ret;
	int		ret2;

	lst = e->a;
	ret = -1;
	while (e->len_a > 0 && (min_pos = ft_get_min_pos(e)) != -1)
	{
		if ((ret2 = ft_sort_core(&min_pos, &ret, e)) == 0)
			break ;
		else if (ret2 == -1)
			return ;
	}
	while (e->len_b > 0)
		ft_disp_push_a(e);
}
