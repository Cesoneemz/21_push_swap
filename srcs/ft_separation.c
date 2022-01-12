/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_separation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:30:34 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/12 13:11:35 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_argv_separate(int argc, char **argv)
{
	int		index;
	char	**result;

	index = 1;
	if (argc == 2 && ft_check_only_spaces(argv[index]))
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
	result[index - 1] = 0;
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

void	ft_free_args(int argc, char **argv)
{
	int	index;

	index = 0;
	while (argv[index] && argc == 2)
	{
		free(argv[index]);
		index++;
	}
	free(argv);
}
