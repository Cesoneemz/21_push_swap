/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:00 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/24 17:58:11 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* static t_score	*ft_init_score(void)
{
	t_score	*node;

	node = (t_score *)malloc(sizeof(t_score));
	if (!node)
		return (NULL);
	node->score_a_r = 0;
	node->score_a_rr = 0;
	node->score_b_r = 0;
	node->score_b_rr = 0;
	return (node);
} */

void	ft_count_score_to_elem(t_stack *stack, int size)
{
	int		index;
	t_stack	*buf;

	index = -1;
	buf = stack;
	while (++index <= size / 2)
	{
		buf->score = index;
		buf->rotate = 1;
		buf = stack->next;
	}
	if (size % 2 == 0)
		index--;
	while (--index > 0)
	{
		buf->score = index;
		buf->rotate = -1;
		buf = stack->next;
	}
}
