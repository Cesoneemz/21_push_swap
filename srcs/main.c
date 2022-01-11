/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:03:45 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/11 16:21:52 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_write_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

char	**ft_argv_separate(int argc, char **argv)
{
	int		index;
	char	**result;

	index = 1;
	if (ft_check_only_spaces(argv[index]) && argc == 2)
	{
		result = ft_split(argv[index], ' ');
		return (result);
	}
	result = (char **)malloc((argc + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (index < argc)
	{
		result[index - 1] = argv[index];
		index++;
	}
	return (result);
}

int	ft_countword(char **split_argv)
{
	int	index;

	index = 0;
	while (split_argv[index])
		index++;
	return (index);
}

void	ft_free_args(char **argv)
{
	int	index;

	index = 0;
	while (argv[index])
	{
		free(argv[index]);
		index++;
	}
	free(argv);
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
		return (0);
	stacks = ft_create_stacks(ft_countword(split_argv), split_argv, str);
	if (!stacks)
		return (0);
	if (stacks->size <= 5)
		ft_sort_small_stack(stacks);
	else
		ft_sort_big_stack(ft_countword(split_argv), stacks);
	free(str);
	ft_free_args(split_argv);
	ft_free_stacks(&stacks);
	return (0);
}
