/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/10 19:18:19 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_input(char **argv, int argc, t_env *e)
{
	int		tmp;
	int		i;

	i = 0;
	while (argv[argc][i])
	{
		if (ft_isdigit(argv[argc][i]) == 0
				&& argv[argc][i] != '-'
				&& argv[argc][i] != '+')
		{
			ft_putstr("Error\n");
			exit(-1);
		}
		i++;
	}
	tmp = ft_atoi_error_exit(argv[argc], "Error\n");
	e->len_a++;
	ft_lstadd(&(e->a), ft_lstnew((void *)(&tmp), sizeof(tmp)));
}

static void	ft_fill_stack_core(char **argv, int argc, t_env *e)
{
	int	i;

	i = 0;
	if (ft_strcmp(argv[argc], "-c") == 0)
		e->flag_c = 1;
	else if (ft_strcmp(argv[argc], "-v") == 0)
		e->flag_v = 1;
	else if (ft_strcmp(argv[argc], "-n") == 0)
		e->flag_n = 1;
	else if (ft_strcmp(argv[argc], "-cv") == 0
			|| ft_strcmp(argv[argc], "-vc") == 0)
	{
		e->flag_v = 1;
		e->flag_c = 1;
	}
	else
		ft_check_input(argv, argc, e);
}

static void	ft_fill_stack(int argc, char **argv, t_env *e)
{
	e->a = NULL;
	e->b = NULL;
	e->len_a = 0;
	e->len_b = 0;
	e->flag_v = 0;
	e->flag_c = 0;
	e->flag_n = 0;
	e->nb_op = 0;
	while (--argc > 0)
		ft_fill_stack_core(argv, argc, e);
}

static void	ft_duplicate(t_list *lst)
{
	t_list	*lst2;
	t_list	*beg;
	int		i;
	int		n;

	i = 0;
	lst2 = lst;
	beg = lst;
	while (lst)
	{
		lst2 = beg;
		n = 0;
		while (lst2)
		{
			if (*(int *)lst2->content == *(int *)lst->content && i != n)
			{
				ft_putstr("Error\n");
				exit(-1);
			}
			n++;
			lst2 = lst2->next;
		}
		i++;
		lst = lst->next;
	}
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		i;

	i = 0;
	env.op = ft_strnew(0);
	ft_fill_stack(argc, argv, &env);
	ft_duplicate(env.a);
	ft_sort_stack(&env);
	if (env.flag_v == 0)
	{
		if (env.flag_c == 1)
			ft_color_disp(1, &env);
		else
			ft_putstr(env.op);
		ft_putchar('\n');
	}
	if (env.flag_n == 1)
	{
		ft_putnbr(env.nb_op);
		ft_putchar('\n');
	}
	ft_strdel(&(env.op));
	ft_free_lst(&env);
}
