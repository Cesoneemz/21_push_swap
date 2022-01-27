/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:03:45 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 16:41:33 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_free_all(int argc, char **sa, t_stacks *stacks, int *str)
{	
	free(str);
	ft_free_args(argc, sa);
	ft_free_stacks(&stacks);
}

static void	ft_sort_delegate(t_stacks *stacks)
{
	if (stacks->size <= 5)
		ft_sort_small_stack(stacks);
	else
		ft_insertion_sort(stacks);
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
		ft_write_error();
	str = ft_sort_str(ft_countword(split_argv), split_argv);
	if (!str)
	{
		ft_free_args(argc, split_argv);
		return (0);
	}
	stacks = ft_create_stacks(ft_countword(split_argv), split_argv);
	if (!stacks)
		return (0);
	ft_sort_delegate(stacks);
	ft_free_all(argc, split_argv, stacks, str);
	return (0);
}
