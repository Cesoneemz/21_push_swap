/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:46:18 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/26 13:42:54 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	tmp = stack;
	size = 1;
	if (!stack)
		return (0);
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*ft_top_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_pop_back(t_stack **stack)
{
	t_stack	*tmp;

	tmp = ft_top_stack(*stack);
	if (tmp->prev)
		tmp->prev->next = NULL;
	else
		*stack = NULL;
	free(tmp);
}

void	ft_push_back(t_stack *stack, int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	while (stack->next)
		stack = stack->next;
	stack->next = node;
	node->prev = stack;
	node->next = NULL;
	node->order = -1;
	node->score = 0;
	node->rotate = 0;
	node->data = data;
}

void	ft_free_stacks(t_stacks **stacks)
{
	t_stack	*tmp;
	t_stack	*st_a;
	t_stack	*st_b;

	if ((*stacks)->a)
	{
		st_a = (*stacks)->a;
		while (st_a)
		{
			tmp = (st_a)->next;
			free(st_a);
			st_a = tmp;
		}
	}
	if ((*stacks)->b)
	{
		st_b = (*stacks)->b;
		while (st_b)
		{
			tmp = (st_b)->next;
			free(st_b);
			st_b = tmp;
		}
	}
	free(*stacks);
}
