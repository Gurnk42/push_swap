/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:19:51 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 17:23:02 by ebouther         ###   ########.fr       */
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

static void	ft_print_stack(t_list *lst)
{
	char	*ret;

	ret = ft_strnew(0);
	*ret = '\n';
	while (lst != NULL)
	{
		ret = ft_strjoin_free(ft_strjoin_free(ret, ft_itoa(*((int *)(lst->content)))), ft_strdup("\n"));
		lst = lst->next;
	}
	ret = ft_strrev(ret);
	ft_putstr(ret);
}

/*static void	ft_sort_stack(t_env *e)
{
	
}*/

static void	ft_fill_stack(int argc, char **argv, t_env *e)
{
	int		tmp;
	int		i;

	i = 1;
	e->a = NULL;
	e->b = NULL;
	e->len_a = 0;
	e->len_b = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i++]);
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

	ft_swap_stack('a', &env);

	//PRINT//
	ft_putstr("\n_____STACK_B____\n");
	ft_print_stack(env.b);
	ft_putstr("\n_____STACK_A____\n");
	ft_print_stack(env.a);
	//____//

	ft_rev_rot_stack('a', &env);
	ft_swap_both(&env);
	ft_push_b(&env);
	ft_push_a(&env);
	//	ft_sort_stacks(&env);
	return (0);
}
