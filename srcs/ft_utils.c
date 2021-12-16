/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:27:48 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/16 18:01:44 by wlanette         ###   ########.fr       */
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

long long int	ft_long_atoi(const char *str)
{
	long long int	index;
	int				b;
	int				signe;

	signe = 1;
	b = 0;
	index = 0;
	while (((char)str[b] >= 9 && (char)str[b] <= 13) || (char)str[b] == ' ')
		b++;
	if ((char)str[b] == '-' || (char)str[b] == '+')
	{
		if ((char)str[b] == '-')
			signe *= -1;
		b++;
	}
	while ((char)str[b] >= '0' && (char)str[b] <= '9')
	{
		index = (index * 10) + (char)str[b] - '0';
		b++;
	}
	return (index * signe);
}
