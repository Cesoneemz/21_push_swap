/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:03:45 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/12 14:50:31 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_write_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

int	main(int argc, char **argv)
{
	int			*str;
	t_stacks	*stacks;
	char		**split_argv;

	if (argc <= 2)
		exit(EXIT_FAILURE);
	split_argv = ft_argv_separate(argc, argv);
	if (!ft_validate_data(ft_countword(split_argv), split_argv))
		return (ft_write_error(-1));
	str = ft_sort_str(ft_countword(split_argv), split_argv);
	if (!str)
		exit(EXIT_FAILURE);
	stacks = ft_create_stacks(ft_countword(split_argv), split_argv, str);
	if (!stacks)
		return (0);
	if (stacks->size <= 5)
		ft_sort_small_stack(stacks);
	else
		ft_sort_big_stack(ft_countword(split_argv), stacks);
	free(str);
	ft_free_args(argc, split_argv);
	ft_free_stacks(&stacks);
	return (0);
}
