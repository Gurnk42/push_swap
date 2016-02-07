/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 16:55:13 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	ft_print_stack(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putnbr(*((int *)(lst->content)));
		ft_putchar('\n');
		lst = lst->next;
	}
}

static void	ft_fill_stack(int argc, char **argv, t_env *e)
{
	int		tmp;

	e->a = NULL;
	e->b = NULL;
	e->len_a = 0;
	e->len_b = 0;
	while (--argc > 0)
	{
		tmp = ft_atoi(argv[argc]);
		e->len_a++;
		ft_lstadd(&(e->a), ft_lstnew((void *)(&tmp), sizeof(tmp)));
	}
}

int	main(int argc, char **argv)
{
	t_env	env;

	ft_fill_stack(argc, argv, &env);

	ft_putstr("LEN : ");
	ft_putnbr(env.len_a);
	ft_putchar('\n');

	ft_print_stack(env.a);

	ft_rev_rot_stack('a', &env);
	ft_putstr("\n_____STACK_B____\n");
	ft_print_stack(env.b);
	ft_putstr("\n_____STACK_A____\n");
	ft_print_stack(env.a);

	ft_swap_both(&env);
	ft_push_b(&env);
	ft_push_a(&env);
	//	ft_sort_stacks(&env);
	return (0);
}
