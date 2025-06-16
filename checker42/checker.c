/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:52:10 by udumas            #+#    #+#             */
/*   Updated: 2024/01/31 17:41:41 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"
#include "get_next_line/get_next_line.h"

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	b_pile = NULL;
	a_pile = check_and_parse(av, ac);
	if (check_pile(a_pile) == 0)
		return (0);
	if (get_next_command(&a_pile, &b_pile) == 0)
	{
		write(2, "Error\n", 6);
		clean(&a_pile, &b_pile);
		return (0);
	}
	if (is_sorted(a_pile) == 1 && b_pile == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean(&a_pile, &b_pile);
	return (0);
}

int	ft_compare(t_pile **a_pile, t_pile **b_pile, char **line)
{
	if (ft_strncmp(*line, "pb\n", 3) == 0)
		push_distribute(a_pile, b_pile, "pb", 0);
	else if (ft_strncmp(*line, "ra\n", 3) == 0)
		rotate_distribute(a_pile, NULL, "ra", 0);
	else if (ft_strncmp(*line, "rb\n", 3) == 0)
		rotate_distribute(NULL, b_pile, "rb", 0);
	else if (ft_strncmp(*line, "rra\n", 4) == 0)
		reverse_rotate_distribute(a_pile, NULL, "rra", 0);
	else if (ft_strncmp(*line, "rrb\n", 4) == 0)
		reverse_rotate_distribute(NULL, b_pile, "rrb", 0);
	else if (ft_strncmp(*line, "rrr\n", 4) == 0)
		reverse_rotate_distribute(a_pile, b_pile, "rrr", 0);
	else if (ft_strncmp(*line, "rr\n", 3) == 0)
		rotate_distribute(a_pile, b_pile, "rr", 0);
	else
		return (free(*line), get_next_line(0, NULL, 1), 0);
	return (1);
}

int	get_next_command(t_pile **a_pile, t_pile **b_pile)
{
	char	*line;

	while (get_next_line(0, &line, 0) != 0)
	{
		if (ft_strncmp(line, "sa\n", 3) == 0)
			swap_distribute(a_pile, b_pile, "sa", 0);
		else if (ft_strncmp(line, "sb\n", 3) == 0)
			swap_distribute(a_pile, b_pile, "sb", 0);
		else if (ft_strncmp(line, "ss\n", 3) == 0)
			swap_distribute(a_pile, b_pile, "ss", 0);
		else if (ft_strncmp(line, "pa\n", 3) == 0)
			push_distribute(a_pile, b_pile, "pa", 0);
		else if (ft_compare(a_pile, b_pile, &line) == 0)
			return (0);
		free(line);
	}
	return (1);
}

void	clean(t_pile **a_pile, t_pile **b_pile)
{
	t_pile	*tmp;
	t_pile	*travel;

	if (*a_pile != NULL)
	{
		travel = (*a_pile)->next;
		while (travel != *a_pile)
		{
			tmp = travel->next;
			free(travel);
			travel = tmp;
		}
		free(*a_pile);
	}
	if (*b_pile != NULL)
	{
		travel = (*b_pile)->next;
		while (travel != *b_pile)
		{
			tmp = travel->next;
			free(travel);
			travel = tmp;
		}
		free(*b_pile);
	}
}
