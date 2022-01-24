/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:07:19 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/24 18:37:51 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_smaller_elem_detect(t_stack *a, int buf, int src)
{
	t_stack	*tmp;
	int		result;

	tmp = a;
	result = 0;
	while (tmp && result == 0)
	{
		if (tmp->data < buf && tmp->data > src)
			result = 1;
		tmp = tmp->next;
	}
	return (result);
}

void	ft_help_finding_place(t_stacks *s, t_stack *b, int *action, int *buf)
{
	while (s->a)
	{
		*buf = s->a->data;
		if (b->data > s->a->data)
		{
			*action += 1;
			if (s->a->next->data > b->data)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_smaller_elem_detect(s->a, *buf, b->data))
	{
		while (s->a)
		{
			if (s->a->data < *buf && s->a->data > b->data)
				break ;
			*action += 1;
			s->a = s->a->next;
		}
	}
}

int	ft_finding_place(t_stacks *stacks, t_stack *b, t_score *score, int min)
{
	int	action;
	int	buf;
	int	result;

	action = 0;
	buf = 0;
	ft_help_finding_place(stacks, b, &action, &buf);
	if (stacks->a->rotate == -1)
		action = ft_get_stack_size(stacks->a) - action;
	if (min == -1 || (action + b->score) < min)
	{
		score->dest_a = stacks->a->rotate;
		score->dest_b = b->rotate;
		score->count_a = action;
		score->count_b = b->score;
		result = action + b->score;
	}
	else
		result = min;
	return (result);
}

int	ft_count_to_min(t_stack *a, int min)
{
	int		index;

	index = 0;
	while (a)
	{
		if (a->data == min)
			break ;
		index++;
		a = a->next;
	}
	return (index);
}
