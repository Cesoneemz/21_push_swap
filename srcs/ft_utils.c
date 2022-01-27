/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:27:48 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 15:29:22 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index])
		index++;
	return (s2[index] - s1[index]);
}

long	ft_long_atoi(const char *str)
{
	long		res;
	long		n;

	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	res = 0;
	n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (n * res);
}

t_bool	ft_is_number(char *num)
{
	int	index;

	index = 0;
	if (num[index] == '+' || num[index] == '-')
		index++;
	while (num[index])
	{
		if (!ft_isdigit(num[index]))
			return (false);
		index++;
	}
	return (true);
}

int	ft_write_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}
