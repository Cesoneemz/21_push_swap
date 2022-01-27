/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:12:18 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/27 18:07:38 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_check_command(char *line, t_stacks *stacks)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(&stacks->a, false);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(&stacks->b, false);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(&stacks->a, &stacks->b, false);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(&stacks->a, &stacks->b, stacks, false);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(&stacks->a, &stacks->b, stacks, false);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(&stacks->a, false);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(&stacks->b, false);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(&stacks->a, &stacks->b, false);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(&stacks->a, false);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(&stacks->b, false);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(&stacks->a, &stacks->b, false);
	else
		ft_write_error();
	free(line);
}

void	ft_sort_by_action(t_stacks *stacks)
{
	char	*line;
	char	*tmp;

	line = get_next_line(0);
	while (line)
	{
		tmp = line;
		free(line);
		line = ft_strtrim(tmp, "\n");
		ft_check_command(line, stacks);
		line = get_next_line(0);
	}
	free(line);
}

t_bool	ft_check_stacks_sorted(t_stacks *stacks)
{
	t_stack	*top_a;
	int		index;
	int		buf;

	index = 0;
	top_a = ft_top_stack(stacks->a);
	while (index < ft_get_stack_size(stacks->a) - 1)
	{
		buf = top_a->data;
		top_a = top_a->prev;
		if (buf > top_a->data)
			return (false);
		index++;
	}
	return (true);
}

static void	ft_free_all(int argc, char **sa, t_stacks *stacks)
{	
	ft_free_args(argc, sa);
	ft_free_stacks(&stacks);
}

int	main(int argc, char **argv)
{
	char		**split_argv;
	t_stacks	*stacks;

	if (!argv[1])
		exit(EXIT_FAILURE);
	split_argv = ft_argv_separate(argc, argv);
	if (ft_countword(split_argv) < 2)
		ft_write_error();
	if (!ft_validate_data(ft_countword(split_argv), split_argv))
		ft_write_error();
	stacks = ft_create_stacks(ft_countword(split_argv), split_argv);
	if (!stacks)
		return (0);
	ft_sort_by_action(stacks);
	if (ft_get_stack_size(stacks->b) == 0 && ft_check_stacks_sorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_all(argc, split_argv, stacks);
}
