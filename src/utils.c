/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:02:56 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/10 19:18:18 by ebouther         ###   ########.fr       */
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

void	ft_free_lst(t_env *e)
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

int		ft_get_min_pos(t_env *e)
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

int		ft_is_sort(t_list *lst, size_t len)
{
	int	tmp;
	int	i;
	int	max;
	int	max_pos = -1;

	i = 0;
	tmp = -2147483648;
	max = -2147483648;
	while (lst != NULL)
	{
		if (*((int *)lst->content) >= max)
		{
			max_pos = i;
			max = tmp;
		}
		if (tmp > *((int *)lst->content))
		{
			if (i == (int)(len - 1) && len > 3 && max_pos == i)
				return (2);
			return (0);
		}
		tmp = *((int *)lst->content);
		i++;
		lst = lst->next;
	}
	return (1);
}
