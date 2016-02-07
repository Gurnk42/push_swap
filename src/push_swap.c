/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 23:57:44 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	if ((join = (char *)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))) == NULL)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (join);
}

static void	ft_free_lst(t_env *e)
{
	t_list	*tmp;

	tmp = NULL;
	while (e->a != NULL)
	{
		tmp = e->a;
		e->a = e->a->next;
		ft_memdel((void **)&(tmp->content));
		ft_memdel((void **)&(tmp));
	}
	while (e->b != NULL)
	{
		tmp = e->b;
		e->b = e->b->next;
		ft_memdel((void **)&(tmp->content));
		ft_memdel((void **)&(tmp));
	}
}

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

static void	ft_sort_stack(t_env *e)
{
	int	i;
	t_list	*lst;
	int	min_pos;

	lst = e->a;
	while (e->len_a > 0 && (min_pos = ft_get_min_pos(e)) != -1)
	{
		i = 0;
		while (i < min_pos)
		{
			ft_rot_stack('a', e);
			if (*(e->op) != '\0')
				e->op = ft_strjoin_free(e->op, ft_strdup(" "));
			e->op = ft_strjoin_free(e->op, ft_strdup("ra"));
			i++;
		}
		ft_push_b(e);
		if (*(e->op) != '\0')
			e->op = ft_strjoin_free(e->op, ft_strdup(" "));
		e->op = ft_strjoin_free(e->op, ft_strdup("pb"));
	}
	while (e->len_b > 0)
	{
		if (*(e->op) != '\0')
			e->op = ft_strjoin_free(e->op, ft_strdup(" "));
		e->op = ft_strjoin_free(e->op, ft_strdup("pa"));
		ft_push_a(e);
	}
}

int	main(int argc, char **argv)
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

	//ft_sort_stack(&env);
	ft_putendl(env.op);
	ft_strdel(&(env.op));
	ft_free_lst(&env);
while (1) ;
	return (0);
}
