/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/09 19:18:22 by ebouther         ###   ########.fr       */
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
	tmp = ft_atoi(argv[argc]);
	e->len_a++;
	ft_lstadd(&(e->a), ft_lstnew((void *)(&tmp), sizeof(tmp)));
}

static void	ft_fill_stack_core(char **argv, int argc, t_env *e)
{
	if (ft_strcmp(argv[argc], "-c") == 0)
		e->flag_c = 1;
	else if (ft_strcmp(argv[argc], "-v") == 0)
		e->flag_v = 1;
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
	int		nb[argc];

	e->a = NULL;
	e->b = NULL;
	e->len_a = 0;
	e->len_b = 0;
	e->flag_v = 0;
	e->flag_c = 0;
	while (--argc > 0)
		ft_fill_stack_core(argv, argc, e);
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		i;

	i = 0;
	env.op = ft_strnew(0);
	ft_fill_stack(argc, argv, &env);
	ft_sort_stack(&env);
	if (env.flag_v == 0)
	{
		if (env.flag_c == 1)
		{
			while (i < ft_strlen(env.op) - 2)
				ft_putchar(env.op[i++]);
			ft_putstr("\033[33m");
			ft_putstr(env.op + i);
			ft_putstr("\033[0m");
		}
		else
			ft_putstr(env.op);
		ft_putchar('\n');
	}
	ft_strdel(&(env.op));
	ft_free_lst(&env);
}
