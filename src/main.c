/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:41:14 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 18:56:23 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	launch_algo(t_pile **a_pile, t_pile **b_pile)
{
	if (ft_lstsize(*a_pile) <= 250)
		push_start(a_pile, b_pile);
	add_index_groups(a_pile);
	if (is_sorted(*a_pile) == 0)
	{
		if (ft_lstsize(*a_pile) < 250)
		{
			while (ft_lstsize(*a_pile) > 3)
			{
				attribuate_link(a_pile, b_pile);
				calculate_steps(a_pile, ft_lstsize(*b_pile));
				push_a_to_b_order(a_pile, b_pile);
			}
		}
		else
			push_by_groups(a_pile, b_pile);
	}
	particular_case(a_pile, 1);
	push_b_to_a_order(a_pile, b_pile, ft_lstsize(*b_pile)
		+ ft_lstsize(*a_pile));
	last_check(a_pile);
}

void	last_check(t_pile **a_pile)
{
	t_pile	*smallest;

	smallest = find_smallest_number(a_pile);
	while (1)
	{
		smallest = find_smallest_number(a_pile);
		if (smallest->rank == 0)
			break ;
		if (smallest->position == 1)
			rotate_distribute(a_pile, NULL, "ra", 1);
		else
			reverse_rotate_distribute(a_pile, NULL, "rra", 1);
	}
}

int	main(int ac, char **av)
{
	t_pile	*a_pile;
	t_pile	*b_pile;

	b_pile = NULL;
	a_pile = check_and_parse(av, ac);
	if (check_pile(a_pile) == 0)
		return (0);
	set_rank(a_pile);
	set_prec(a_pile);
	if (ft_lstsize(a_pile) == 2)
		particular_case(&a_pile, 0);
	else if (ft_lstsize(a_pile) == 3)
		particular_case(&a_pile, 1);
	else if (ft_lstsize(a_pile) > 3 && ft_lstsize(a_pile) < 400)
		launch_algo(&a_pile, &b_pile);
	else if (ft_lstsize(a_pile) >= 400)
		launch_algo(&a_pile, &b_pile);
	ft_cleanpile(&a_pile);
}
