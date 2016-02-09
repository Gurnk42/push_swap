/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/09 12:16:31 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	ft_print_stack(t_list *lst)
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

static void	ft_fill_stack(int argc, char **argv, t_env *e)
{
	int		tmp;
	int		i;
	int		nb[argc];

	i = 0;
	e->a = NULL;
	e->b = NULL;
	e->len_a = 0;
	e->len_b = 0;
	while (--argc > 0)
	{
		while (argv[argc][i])
		{
			if (ft_isdigit(argv[argc][i++]) == 0)
			{
				ft_putstr("Error\n");
				exit(-1);
			}
		}
		tmp = ft_atoi(argv[argc]);
		e->len_a++;
		ft_lstadd(&(e->a), ft_lstnew((void *)(&tmp), sizeof(tmp)));
	}
}

static int	ft_get_min_pos(t_env *e)
{
	int		min;
	int		min_pos;
	t_list	*lst;
	int		i;

	min = 2147483647;
	min_pos = -1;
	i = 0;
	lst = e->a;
	while (lst != NULL)
	{
		if (*((int *)lst->content) <= min)
		{
			min = *((int *)lst->content);
			min_pos = i;
		}
		i++;
		lst = lst->next;
	}
	if (min_pos != -1)
		return (min_pos);
	return (-1);
}

static int	ft_is_sort(t_list *lst, size_t len)
{
	int	tmp;

	tmp = -2147483648;
	while (lst != NULL)
	{
		if (tmp > *((int *)lst->content))
			return (0);
		tmp = *((int *)lst->content);
		lst = lst->next;
	}
	return (1);
}

static void	ft_sort_stack(t_env *e)
{
	int		i;
	t_list	*lst;
	int		min_pos;

	lst = e->a;
	while (e->len_a > 0 && (min_pos = ft_get_min_pos(e)) != -1)
	{
	/*	ft_putstr("a : ");
		ft_print_stack(e->a);
		ft_putchar('\n');
		ft_putstr("b : ");
		ft_print_stack(e->b);
		ft_putchar('\n');*/
		if (ft_is_sort(e->a, e->len_a) == 1)
		{
			while (e->len_b > 0)
			{
				if (*(e->op) != '\0')
					e->op = ft_strjoin_free(e->op, ft_strdup(" "));
				e->op = ft_strjoin_free(e->op, ft_strdup("pa"));
				ft_push_a(e);
			}
			return ;
		}
		i = 0;
		if (min_pos == 1)
		{
			ft_swap_stack('a', e);
			if (*(e->op) != '\0')
				e->op = ft_strjoin_free(e->op, ft_strdup(" "));
			e->op = ft_strjoin_free(e->op, ft_strdup("sa"));
			i++;
		}
		else if (min_pos <= e->len_a / 2)
		{
			while (i < min_pos)
			{
				ft_rot_stack('a', e);
				if (*(e->op) != '\0')
					e->op = ft_strjoin_free(e->op, ft_strdup(" "));
				e->op = ft_strjoin_free(e->op, ft_strdup("ra"));
				i++;
			}
		}
		else
		{
			while (i < (e->len_a - min_pos))
			{
				ft_rev_rot_stack('a', e);
				if (*(e->op) != '\0')
					e->op = ft_strjoin_free(e->op, ft_strdup(" "));
				e->op = ft_strjoin_free(e->op, ft_strdup("rra"));
				i++;
			}
		}
		if (ft_is_sort(e->a, e->len_a) != 1)
		{
			ft_push_b(e);
			if (*(e->op) != '\0')
				e->op = ft_strjoin_free(e->op, ft_strdup(" "));
			e->op = ft_strjoin_free(e->op, ft_strdup("pb"));
		}
	}
	while (e->len_b > 0)
	{
		if (*(e->op) != '\0')
			e->op = ft_strjoin_free(e->op, ft_strdup(" "));
		e->op = ft_strjoin_free(e->op, ft_strdup("pa"));
		ft_push_a(e);
	}
}

int			main(int argc, char **argv)
{
	t_env	env;

	env.op = ft_strnew(0);
	ft_fill_stack(argc, argv, &env);
	/*
	   ft_print_stack(env.a);
	   ft_swap_stack('a', &env);
	   ft_push_b(&env);
	   ft_push_b(&env);
	   ft_push_b(&env);
	   ft_rot_both(&env);
	   ft_rev_rot_both(&env);
	   ft_swap_stack('a', &env);
	   ft_push_a(&env);
	   ft_push_a(&env);
	   ft_push_a(&env);
	   */
	ft_sort_stack(&env);
	ft_putendl(env.op);
	ft_strdel(&(env.op));

	ft_print_stack(env.a);
	ft_free_lst(&env);
}
