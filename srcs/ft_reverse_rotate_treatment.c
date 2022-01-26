/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_treatment.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:27:04 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/18 11:29:12 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack **a, t_bool writeable)
{
	t_stack	*tmp;
	t_stack	*head;

	head = (*a)->next;
	tmp = ft_top_stack(*a);
	(*a)->next->prev = NULL;
	(*a)->prev = tmp;
	(*a)->next = NULL;
	tmp->next = *a;
	(*a) = head;
	if (writeable)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, t_bool writeable)
{
	t_stack	*tmp;
	t_stack	*head;

	head = (*b)->next;
	tmp = ft_top_stack(*b);
	(*b)->next->prev = NULL;
	(*b)->prev = tmp;
	(*b)->next = NULL;
	tmp->next = *b;
	(*b) = head;
	if (writeable)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(&(*a), false);
	ft_rrb(&(*b), false);
	write(1, "rrr\n", 4);
}
