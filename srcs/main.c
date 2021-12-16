/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:03:45 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/16 18:01:36 by wlanette         ###   ########.fr       */
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
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (!ft_validate_data(argc, argv))
		return (ft_write_error(-1));
}