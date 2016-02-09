/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 21:20:18 by ebouther          #+#    #+#             */
/*   Updated: 2016/02/09 20:30:57 by ebouther         ###   ########.fr       */
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
	char	*op;
	int		flag_v;
	int		flag_c;
}				t_env;

/*
** swap.c
*/
void			ft_swap_both(t_env *e);
void			ft_swap_stack(char stack, t_env *e);

/*
** rot.c
*/
void			ft_rot_both(t_env *e);
void			ft_rot_stack(char stack, t_env *e);
void			ft_disp_rot_a(t_env *e);
t_list			*ft_get_last(t_list *lst, size_t len);

/*
** rev_rot.c
*/
void			ft_rev_rot_both(t_env *e);
void			ft_rev_rot_stack(char stack, t_env *e);
void			ft_disp_rev_rot_a(t_env *e);

/*
** push.c
*/
void			ft_push_a(t_env *e);
void			ft_push_b(t_env *e);
void			ft_disp_push_a(t_env *e);
void			ft_disp_push_b(t_env *e);

/*
** utils.c
*/
char			*ft_strjoin_free(char *s1, char *s2);
void			ft_free_lst(t_env *e);
int				ft_get_min_pos(t_env *e);
int				ft_is_sort(t_list *lst, size_t len);

/*
** disp.c
*/
void			ft_stacks_state(t_env *e);
void			ft_print_stack(t_list *lst);
void			ft_disp_swap_a(t_env *e);

/*
** sort.c
*/
void			ft_sort_stack(t_env *e);

#endif
