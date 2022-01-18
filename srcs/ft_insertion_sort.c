/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:18:03 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/18 14:13:37 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	ft_get_min_elem_in_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

/* static int	ft_get_max_elem_in_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	tmp = stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
} */

void	ft_insertion_sort(t_stacks *stacks)
{
	int		min;
	t_stack	*top;
	t_stack	*tmp;
	t_bool	flag;

	top = ft_top_stack(stacks->a);
	flag = true;
	tmp = stacks->a;
	while (tmp)
	{
		min = ft_get_min_elem_in_stack(tmp);
		while (top->data != min)
		{
			ft_ra(&stacks->a, true);
			top = ft_top_stack(stacks->a);
		}
		ft_pb(&stacks->a, &stacks->b);
		tmp = stacks->a->next;
		if (!tmp)
			printf("NULL\n");
	}
	while (stacks->b)
	{
		printf("%d\n", stacks->b->data);
		stacks->b = stacks->b->next;
	}
	exit(EXIT_SUCCESS);
}
