/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:06:25 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/16 17:58:41 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	ft_check_only_spaces(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n' || str[index] == '\t' || str[index] == '\v' \
		|| str[index] == ' ' || str[index] == '\r' || str[index] == '\f')
			index++;
		else
			return (true);
	}
	return (false);
}

static t_bool	ft_check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = 1;
		k = 0;
		while (argv[j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				k++;
			j++;
		}
		if (k >= 2)
			return (false);
		i++;
	}
	return (true);
}

static t_bool	ft_check_max_min_int(char **argv)
{
	int	index;
	int	nbr;

	index = 0;
	while (argv[index])
	{
		nbr = ft_long_atoi(argv[index]);
		if (argv[index] >= INT_MAX || argv[index] <= INT_MIN)
			return (false);
		index++;
	}
	return (true);
}

t_bool	ft_validate_data(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc < 2)
		return (false);
	while (argv[index])
	{
		if (!ft_isdigit(argv[index]) && !ft_check_only_spaces(argv[index]))
			return (false);
		index++;
	}
	if (!ft_check_duplicates(argc, argv) && !ft_check_max_min_int(argv))
		return (true);
	return (false);
}
