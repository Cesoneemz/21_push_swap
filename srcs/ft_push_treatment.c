/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:04:30 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 12:39:32 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, t_stacks *stacks)
{
	t_stack	*top_stack_a;
	t_stack	*top_stack_b;
	int		tmp_data;

	if (*b)
	{
		top_stack_b = ft_top_stack(*b);
		tmp_data = top_stack_b->data;
		stacks->size_a++;
		stacks->size_b--;
		ft_pop_back(&(*b));
		if (*a)
			ft_push_back(*a, tmp_data);
		else
			*a = ft_create_stack(tmp_data);
		top_stack_a = ft_top_stack(*a);
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stack **a, t_stack **b, t_stacks *stacks)
{
	t_stack	*top_stack_a;
	t_stack	*top_stack_b;
	int		tmp_data;

	if (*a)
	{
		top_stack_a = ft_top_stack(*a);
		tmp_data = top_stack_a->data;
		stacks->size_b++;
		stacks->size_a--;
		ft_pop_back(&(*a));
		if (*b)
			ft_push_back(*b, tmp_data);
		else
			*b = ft_create_stack(tmp_data);
		top_stack_b = ft_top_stack(*b);
		write(1, "pb\n", 3);
	}
}
