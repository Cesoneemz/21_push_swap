/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:18:03 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 12:36:49 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_push_all_to_b(t_stacks *stacks)
{
	while (ft_get_stack_size(stacks->a) > 2)
	{
		if (ft_top_stack(stacks->a)->data != stacks->min \
		&& ft_top_stack(stacks->a)->data != stacks->max)
		{
			ft_pb(&stacks->a, &stacks->b, stacks);
			if (ft_top_stack(stacks->b)->data > stacks->median)
				ft_rb(&stacks->b, true);
		}
		else
			ft_ra(&stacks->a, true);
	}
	if (ft_top_stack(stacks->a)->data < ft_top_stack(stacks->a)->prev->data)
		ft_sa(&stacks->a, true);
	ft_pa(&stacks->a, &stacks->b, stacks);
}

static void	ft_get_min_ins_score(t_stacks *stacks, t_score *score)
{
	int		min;
	t_stack	*a;
	t_stack	*b;

	min = -1;
	a = stacks->a;
	stacks->a = ft_top_stack(stacks->a);
	b = ft_top_stack(stacks->b);
	while (b)
	{
		min = ft_finding_place(stacks, b, score, min);
		stacks->a = ft_top_stack(stacks->a);
		b = b->prev;
	}
	stacks->a = a;
}

static void	ft_execute(t_stacks *stacks, t_score *score)
{
	while (score->count_a > 0)
	{
		if (score->dest_a == 1)
			ft_ra(&stacks->a, true);
		else
			ft_rra(&stacks->a, true);
		score->count_a--;
	}
	while (score->count_b > 0)
	{
		if (score->dest_b == 1)
			ft_rb(&stacks->b, true);
		else
			ft_rrb(&stacks->b, true);
		score->count_b--;
	}
	ft_pa(&stacks->a, &stacks->b, stacks);
}

static void	ft_push_all_to_a(t_stacks *stacks)
{
	t_score	*score;

	score = (t_score *)malloc(sizeof(t_score));
	if (!score)
		exit(EXIT_FAILURE);
	while (stacks->size_b != 0)
	{
		score->count_a = -1;
		score->count_b = -1;
		score->dest_a = 0;
		score->dest_b = 0;
		ft_count_score_to_elem(stacks->a, stacks->size_a);
		ft_count_score_to_elem(stacks->b, stacks->size_b);
		ft_get_min_ins_score(stacks, score);
		ft_execute(stacks, score);
	}
	if ((ft_count_to_min(stacks->a, stacks->min)) > stacks->size_a / 2)
		while (ft_top_stack(stacks->a)->data != stacks->min)
			ft_rra(&stacks->a, true);
	else
		while (ft_top_stack(stacks->a)->data != stacks->min)
			ft_ra(&stacks->a, true);
	free(score);
}

void	ft_insertion_sort(t_stacks *stacks)
{
	ft_get_mmm(stacks);
	ft_push_all_to_b(stacks);
	ft_push_all_to_a(stacks);
}
