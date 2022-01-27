/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:07:19 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 16:41:01 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	ft_smaller_elem_detect(t_stack *a, int buf, int src)
{
	t_stack	*tmp;
	t_bool	ret;

	tmp = ft_top_stack(a);
	ret = false;
	while (tmp && !ret)
	{
		if (tmp->data < buf && tmp->data > src)
			ret = true;
		tmp = tmp->prev;
	}
	return (ret);
}

static void	ft_help_finding_place(t_stacks *s, int data, int *action, int *buf)
{
	while (s->a)
	{
		*buf = s->a->data;
		if (data > s->a->data)
		{
			*action += 1;
			if (s->a->prev->data > data)
				break ;
			s->a = s->a->prev;
		}
		else
			break ;
	}
	if (ft_smaller_elem_detect(s->a, *buf, data))
	{
		while (s->a)
		{
			if (s->a->data < *buf && s->a->data > data)
				break ;
			*action += 1;
			s->a = s->a->prev;
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
	ft_help_finding_place(stacks, b->data, &action, &buf);
	if (stacks->a->rotate == -1)
		action = stacks->size_a - action;
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
