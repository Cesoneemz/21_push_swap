/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:07:19 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/25 16:41:04 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	ft_smaller_elem_detect(t_stack *a, int buf, int src)
{
	t_stack	*tmp;

	tmp = ft_top_stack(a);
	while (tmp)
	{
		if (tmp->data < buf && tmp->data > src)
			return (true);
		tmp = tmp->prev;
	}
	return (false);
}

void	ft_help_finding_place(t_stack *a, t_stack *b, int *action, int *buf)
{
	while (a)
	{
		*buf = a->data;
		if (b->data > a->data)
		{
			*action += 1;
			if (a->prev->data > b->data)
				break ;
			a = a->prev;
		}
		else
			break ;
	}
	if (ft_smaller_elem_detect(a, *buf, b->data))
	{
		while (a)
		{
			if (a->data < *buf && a->data > b->data)
				break ;
			*action += 1;
			a = a->prev;
		}
	}
}

int	ft_finding_place(t_stack *a, t_stack *b, t_score *score, int min)
{
	int	action;
	int	buf;
	int	result;

	action = 0;
	buf = 0;
	ft_help_finding_place(a, b, &action, &buf);
	if (a->rotate == -1)
		action = ft_get_stack_size(a) - action;
	if (min == -1 || (action + b->score) < min)
	{
		score->dest_a = a->rotate;
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
	t_stack	*top;

	index = 0;
	top = ft_top_stack(a);
	while (top)
	{
		if (top->data == min)
			break ;
		index++;
		top = top->prev;
	}
	return (index);
}
