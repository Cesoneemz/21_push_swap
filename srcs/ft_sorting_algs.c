/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:38:00 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 12:44:06 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_2_elem(t_stacks *stacks)
{
	t_stack	*top;

	top = ft_top_stack(stacks->a);
	if (top->data > top->prev->data)
		ft_sa(&stacks->a, true);
}

static void	ft_sort_3_elem(t_stacks *stacks)
{
	int	max;

	max = ft_get_max_elem_in_stack(stacks->a);
	if (ft_top_stack(stacks->a)->data == max)
		ft_ra(&stacks->a, true);
	if (ft_top_stack(stacks->a)->prev->data == max)
		ft_rra(&stacks->a, true);
	if (ft_top_stack(stacks->a)->data > ft_top_stack(stacks->a)->prev->data)
		ft_sa(&stacks->a, true);
}

static void	ft_sort_4_or_5_elem(t_stacks *stacks)
{
	ft_get_mmm(stacks);
	while (ft_get_stack_size(stacks->b) < 2)
	{
		if (ft_top_stack(stacks->a)->data == stacks->min \
		|| ft_top_stack(stacks->a)->data == stacks->max)
			ft_pb(&stacks->a, &stacks->b, stacks);
		else
			ft_ra(&stacks->a, true);
	}
	ft_sort_3_elem(stacks);
	ft_pa(&stacks->a, &stacks->b, stacks);
	ft_pa(&stacks->a, &stacks->b, stacks);
	if (stacks->a->data == stacks->max)
		ft_ra(&stacks->a, true);
	else
	{
		ft_sa(&stacks->a, true);
		ft_ra(&stacks->a, true);
	}
}

void	ft_sort_small_stack(t_stacks *stacks)
{
	if (stacks->size == 2)
		ft_sort_2_elem(stacks);
	else if (stacks->size == 3)
		ft_sort_3_elem(stacks);
	else if (stacks->size == 4 || stacks->size == 5)
		ft_sort_4_or_5_elem(stacks);
}
