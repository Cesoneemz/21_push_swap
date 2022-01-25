/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_treatment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:34:00 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/25 16:34:45 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_count_score_to_elem(t_stack *stack, int size)
{
	int		index;
	t_stack	*buf;

	index = -1;
	buf = ft_top_stack(stack);
	while (++index <= size / 2)
	{
		buf->score = index;
		buf->rotate = 1;
		buf = buf->prev;
	}
	if (size % 2 == 0)
		index--;
	while (--index > 0)
	{
		buf->score = index;
		buf->rotate = -1;
		buf = buf->prev;
	}
}
