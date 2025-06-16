/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:28:46 by udumas            #+#    #+#             */
/*   Updated: 2024/01/31 15:27:33 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	attribuate_link_a(t_pile **a_pile, t_pile **b_pile)
{
	t_pile	*travel_a;
	t_pile	*travel_b;

	travel_a = *a_pile;
	travel_b = *b_pile;
	while (1)
	{
		travel_b->link = LONG_MAX;
		while (1)
		{
			if (travel_a->number > travel_b->number)
			{
				test_link2(&travel_b, travel_a);
			}
			travel_a = travel_a->next;
			if (travel_a == *a_pile)
				break ;
		}
		if (travel_b->link == LONG_MAX)
			test_link2(&travel_b, find_smallest_number(a_pile));
		travel_b = travel_b->next;
		if (travel_b == *b_pile)
			break ;
	}
}

void	calculate_steps2(t_pile **b_pile, int size_a)
{
	int		size_b;
	t_pile	*travel;

	travel = *b_pile;
	size_b = ft_lstsize(*b_pile);
	while (1)
	{
		travel->steps = travel->rank;
		if (travel->position == 0)
			travel->steps += size_b - travel->rank;
		if (travel->linkposition == 1)
			travel->steps += travel->linkrank;
		else
			travel->steps += size_a - travel->linkrank;
		travel = travel->next;
		if (travel == *b_pile)
			break ;
	}
}

void	set_a_pile2(t_pile **a_pile, t_pile *to_move)
{
	t_pile	*link;
	int		size_a;

	size_a = ft_lstsize(*a_pile);
	link = *a_pile;
	while (link->number != to_move->link)
		link = link->next;
	size_a = ft_lstsize(*a_pile);
	if (link->rank <= size_a / 2)
		while (link->rank != 0)
			rotate_distribute(a_pile, NULL, "ra", 1);
	else
		while (link->rank != 0)
			reverse_rotate_distribute(a_pile, NULL, "rra", 1);
}

void	set_for_groups(t_pile **a_pile, t_pile **b_pile, t_pile *cost_min)
{
	t_pile	*link;

	link = *a_pile;
	while (link->number != cost_min->link)
		link = link->next;
	if (cost_min->position == 1 && link->position == 1)
		rotate_both2(a_pile, b_pile, cost_min);
	else if (cost_min->position == 0 && link->position == 0)
		reverse_rotate_both2(a_pile, b_pile, cost_min);
	set_a_pile3(a_pile, cost_min);
	set_b_pile2(b_pile, cost_min);
}

void	push_b_to_a_order(t_pile **a_pile, t_pile **b_pile, int size)
{
	t_pile	*cost_min;

	while (*b_pile != NULL)
	{
		attribuate_link_a(a_pile, b_pile);
		calculate_steps2(b_pile, ft_lstsize(*a_pile));
		if (size > 250)
		{
			cost_min = cheapest_cost2(*b_pile);
			set_for_groups(a_pile, b_pile, cost_min);
		}
		else
		{
			cost_min = cheapest_cost(*b_pile);
			set_a_pile2(a_pile, cost_min);
		}
		push_distribute(a_pile, b_pile, "pa", 1);
	}
}
