/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:14:19 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 12:31:58 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_max_elem_in_stack(t_stack *stack)
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
}

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

static int	*ft_bubble_sort(int *temp, int size)
{
	int		index;
	int		jndex;
	int		swap;

	index = 0;
	while (index < size - 1)
	{
		jndex = 0;
		while (jndex < size - index - 1)
		{
			if (temp[jndex] > temp[jndex + 1])
			{
				swap = temp[jndex];
				temp[jndex] = temp[jndex + 1];
				temp[jndex + 1] = swap;
			}
			jndex++;
		}
		index++;
	}
	return (temp);
}

static int	ft_get_median_in_stack(t_stack *stack, int size)
{
	t_stack	*tmp;
	int		*temp;
	int		index;
	int		result;

	tmp = stack;
	temp = (int *)malloc((size + 1) * sizeof(int));
	if (!temp)
		return (0);
	index = -1;
	while (tmp)
	{
		temp[++index] = tmp->data;
		tmp = tmp->next;
	}
	result = ft_bubble_sort(temp, size)[size / 2];
	free(temp);
	return (result);
}

void	ft_get_mmm(t_stacks *stacks)
{
	stacks->max = ft_get_max_elem_in_stack(stacks->a);
	stacks->min = ft_get_min_elem_in_stack(stacks->a);
	stacks->median = ft_get_median_in_stack(stacks->a, stacks->size);
	stacks->size_a = ft_get_stack_size(stacks->a);
}
