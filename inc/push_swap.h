/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:20:18 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/07 14:42:40 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_env
{
	t_list	*a;
	size_t	len_a;
	t_list	*b;
	size_t	len_b;
}				t_env;

/*
** swap.c
*/
void	ft_swap_both(t_env *e);
void	ft_swap_stack(char stack, t_env *e);

/*
** rot.c
*/
void	ft_rev_rot_stack(char stack, t_env *e);
void	ft_rot_both(t_env *e);
void	ft_rot_stack(char stack, t_env *e);

/*
** push.c
*/
void	ft_push_a(t_env *e);
void	ft_push_b(t_env *e);

#endif
