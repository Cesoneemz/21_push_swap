/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_treatment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:21:49 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/23 12:58:01 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*tmp;
	int		stack_size;

	stack_size = ft_get_stack_size(*a);
	if (stack_size > 2)
	{
		tmp = ft_top_stack(*a);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*a)->prev = tmp;
		tmp->next = *a;
		*a = tmp;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_stack **b)
{
	t_stack	*tmp;
	int		stack_size;

	stack_size = ft_get_stack_size(*b);
	if (stack_size > 2)
	{
		tmp = ft_top_stack(*b);
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*b)->prev = tmp;
		tmp->next = *b;
		*b = tmp;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(&(*a));
	ft_rb(&(*b));
	write(1, "rr\n", 3);
}