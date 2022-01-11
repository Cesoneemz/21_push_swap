/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:29:36 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/10 15:51:36 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_swap_elem(int *result, int index, int jndex)
{
	int	tmp;

	tmp = result[index];
	result[index] = result[jndex];
	result[jndex] = tmp;
}

static void	ft_quick_sort(int *result, int first, int last)
{
	int	index;
	int	jndex;
	int	pivot;
	int	tmp;

	pivot = first;
	index = first;
	jndex = last;
	if (first < last)
	{
		while (index < jndex)
		{
			while (result[index] <= result[pivot] && index < last)
				index++;
			while (result[jndex] > result[pivot])
				jndex--;
			if (index < jndex)
				ft_swap_elem(result, index, jndex);
		}
		tmp = result[pivot];
		result[pivot] = result[jndex];
		result[jndex] = tmp;
		ft_quick_sort(result, first, jndex - 1);
		ft_quick_sort(result, jndex + 1, last);
	}
}

static t_bool	ft_check_sorted(const int *result, int size)
{
	int	index;

	index = 0;
	while (index < size - 1)
	{
		if (result[index] > result[index + 1])
			return (false);
		index++;
	}
	return (true);
}

int	*ft_sort_str(int argc, char **argv)
{
	int	*result;
	int	index;
	int	jndex;

	result = (int *)malloc((argc - 1) * sizeof(int));
	if (!result)
		return (0);
	index = 1;
	jndex = 0;
	while (jndex < (argc - 1))
		result[jndex++] = ft_atoi(argv[index++]);
	if (ft_check_sorted(result, jndex))
	{
		free(result);
		return (0);
	}
	ft_quick_sort(result, 0, jndex - 1);
	return (result);
}
