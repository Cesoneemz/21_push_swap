/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:46:18 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/22 17:28:37 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*tmp;
	int		size;

	tmp = stack;
	size = 1;
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
	while (stack->next)
		stack = stack->next;
	stack->next = node;
	node->prev = stack;
	node->next = NULL;
	node->order = -1;
	node->data = data;
}
