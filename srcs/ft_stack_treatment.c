/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:02:13 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 12:39:59 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_create_stack(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->data = value;
	node->score = 0;
	node->rotate = 0;
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
	stacks->size = argc;
	stacks->min = 0;
	stacks->max = 0;
	stacks->median = 0;
	stacks->size_a = 0;
	stacks->size_b = 0;
	return (stacks);
}

t_stacks	*ft_create_stacks(int argc, char **argv)
{
	t_stacks	*stacks;
	int			index;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks = ft_init_stack(stacks, argc, argv);
	index = argc - 2;
	while (index >= 0)
	{
		ft_push_back(stacks->a, ft_atoi(argv[index]));
		index--;
	}
	return (stacks);
}
