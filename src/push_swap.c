/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 00:00:14 by ebouther         ###   ########.fr       */
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

static void	ft_swap_stack(char stack, t_env *e)
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

static void	ft_push_a(t_env *e)
{
	void	*tmp;

	if (e->len_b >= 1)
	{
		ft_lstadd(&(e->a), ft_lstnew(e->b->content, sizeof(tmp)));
		tmp = e->b->next;
		e->b = NULL;
		e->b = tmp;
	}
}

static void	ft_push_b(t_env *e)
{
	void	*tmp;

	if (e->len_a >= 1)
	{
		ft_lstadd(&(e->b), ft_lstnew(e->a->content, sizeof(tmp)));
		tmp = e->a->next;
		e->a = NULL;
		e->a = tmp;
	}
}

static void	ft_swap_both(t_env *e)
{
	ft_swap_stack('a', e);
	ft_swap_stack('b', e);
}

static void	ft_rot_stack(char stack, t_env *e)
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
		printf("FIRST : '%d'\n", *(int *)first);
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

	ft_rot_stack('a', &env);
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
