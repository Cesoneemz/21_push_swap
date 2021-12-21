/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_treatment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:43:56 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/22 00:03:32 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack **stack)
{
	t_stack	*top;
	int		tmp_data;
	int		tmp_order;
	int		stack_size;

	stack_size = ft_get_stack_size(*stack);
	if (stack_size >= 2)
	{
		tmp_data = ft_top_stack(*stack)->prev->data;
		tmp_order = ft_top_stack(*stack)->prev->order;
		top = ft_top_stack(*stack);
		top->prev->data = top->data;
		top->prev->order = top->order;
		top->data = tmp_data;
		top->order = tmp_order;
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_stack **stack)
{
	t_stack	*top;
	int		tmp_data;
	int		tmp_order;
	int		stack_size;

	stack_size = ft_get_stack_size(*stack);
	if (stack_size >= 2)
	{
		tmp_data = ft_top_stack(*stack)->prev->data;
		tmp_order = ft_top_stack(*stack)->prev->order;
		top = ft_top_stack(*stack);
		top->prev->data = top->data;
		top->prev->order = top->order;
		top->data = tmp_data;
		top->order = tmp_order;
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(&(*a));
	ft_sb(&(*b));
	write(1, "ss\n", 3);
}
