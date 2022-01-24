/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:03:45 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/24 16:42:38 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_write_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

static void	ft_free_all(int argc, char **sa, t_stacks *stacks, int *str)
{	
	free(str);
	ft_free_args(argc, sa);
	ft_free_stacks(&stacks);
}

int	main(int argc, char **argv)
{
	int			*str;
	t_stacks	*stacks;
	char		**split_argv;

	if (argc < 2)
		exit(EXIT_FAILURE);
	split_argv = ft_argv_separate(argc, argv);
	if (!ft_validate_data(ft_countword(split_argv), split_argv))
		return (ft_write_error(-1));
	str = ft_sort_str(ft_countword(split_argv), split_argv);
	if (!str)
	{
		ft_free_args(argc, split_argv);
		return (0);
	}
	stacks = ft_create_stacks(ft_countword(split_argv), split_argv, str);
	if (!stacks)
		return (0);
	ft_insertion_sort(stacks);
/* 	if (stacks->size <= 5)
		ft_sort_small_stack(stacks);
	else
		ft_sort_big_stack(ft_countword(split_argv), stacks); */
	ft_free_all(argc, split_argv, stacks, str);
	return (0);
}
