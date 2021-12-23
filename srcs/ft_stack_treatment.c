/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:02:13 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/22 00:30:29 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_search_order(int value, const int *sorted)
{
	int	index;

	index = 0;
	while (1)
	{
		if (sorted[index] == value)
			return (index + 1);
		index++;
	}
}

void	ft_index_stack(t_stack *a, int *result)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->order = ft_search_order(tmp->data, result);
		tmp = tmp->next;
	}
}

t_stack	*ft_create_stack(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = value;
	node->order = 0;
	return (node);
}

t_stacks	*ft_init_stack(t_stacks *stacks, int argc, char **argv)
{
	int	index;

	index = ft_atoi(argv[argc - 1]);
	stacks->a = ft_create_stack(index);
	if (!stacks->a)
		return (NULL);
	stacks->b = NULL;
	stacks->size = argc - 1;
	return (stacks);
}

t_stacks	*ft_create_stacks(int argc, char **argv, int *result)
{
	t_stacks	*stacks;
	int			index;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	ft_init_stack(stacks, argc, argv);
	index = argc - 2;
	while (index >= 1)
	{
		ft_push_back(stacks->a, ft_atoi(argv[index]));
		index--;
	}
	ft_index_stack(stacks->a, result);
	return (stacks);
}