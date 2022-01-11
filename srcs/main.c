/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:03:45 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/11 15:35:24 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_write_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

int	main(int argc, char **argv)
{
	int			*str;
	t_stacks	*stacks;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (!ft_validate_data(argc, argv))
		return (ft_write_error(-1));
	str = ft_sort_str(argc, argv);
	if (!str)
		return (0);
	stacks = ft_create_stacks(argc, argv, str);
	if (!stacks)
		return (0);
	if (stacks->size <= 5)
		ft_sort_small_stack(stacks);
	else
		ft_sort_big_stack(argc, stacks);
	free(str);
	ft_free_stacks(&stacks);
	return (0);
}
