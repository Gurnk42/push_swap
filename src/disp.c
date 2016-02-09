/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:25:10 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/10 00:32:15 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *lst)
{
	char	*ret;

	ret = ft_strnew(0);
	while (lst != NULL)
	{
		ret = ft_strjoin_free(ft_strdup(" "),
				ft_strjoin_free(ft_itoa(*((int *)(lst->content))), ret));
		lst = lst->next;
	}
	ft_putstr(ret);
	ft_strdel(&ret);
}

void	ft_color_disp(int color, t_env *e)
{
	int		len;
	int		i;

	i = 0;	
	len = (int)ft_strlen(e->op);
	while (i < ((len - 3 >= 0) ? (len - 3) : 0))
		ft_putchar(e->op[i++]);
	ft_putstr("\033[3");
	ft_putnbr((color % 6) + 1);
	ft_putstr("m");
	ft_putstr(e->op + i);
	ft_putstr("\033[0m");
}

void	ft_stacks_state(t_env *e)
{
	static int	color = 0;

	ft_putchar('\n');
	if (e->flag_c == 1)
	{
		ft_color_disp(color, e);
		color++;
	}
	else
		ft_putstr(e->op);
	ft_putstr("\na:");
	ft_print_stack(e->a);
	ft_putstr("\nb:");
	ft_print_stack(e->b);
	ft_putchar('\n');
}
