/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:11:19 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 18:58:18 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rotate_both(t_pile **a_pile, t_pile **b_pile, t_pile *to_move)
{
	t_pile	*link;

	link = *b_pile;
	while (link->number != to_move->link)
		link = link->next;
	while (1)
	{
		if (to_move->rank == 0 || link->rank == 0)
			break ;
		rotate_distribute(a_pile, b_pile, "rr", 1);
	}
}

void	reverse_rotate_both(t_pile **a_pile, t_pile **b_pile, t_pile *to_move)
{
	t_pile	*link;

	link = *b_pile;
	while (link->number != to_move->link)
		link = link->next;
	while (1)
	{
		if (to_move->rank == 0 || link->rank == 0)
			break ;
		reverse_rotate_distribute(a_pile, b_pile, "rrr", 1);
	}
}

void	set_a_pile(t_pile **a_pile, t_pile *to_move)
{
	int	size_a;

	size_a = ft_lstsize(*a_pile);
	while (to_move->rank != 0)
	{
		if (to_move->position == 1)
			rotate_distribute(a_pile, NULL, "ra", 1);
		else
			reverse_rotate_distribute(a_pile, NULL, "rra", 1);
	}
}

void	set_b_pile(t_pile **b_pile, t_pile *to_move)
{
	t_pile	*link;
	int		size_b;

	link = *b_pile;
	while (link->number != to_move->link)
		link = link->next;
	size_b = ft_lstsize(*b_pile);
	while (link->rank != 0)
	{
		if (link->position == 1)
			rotate_distribute(NULL, b_pile, "rb", 1);
		else
			reverse_rotate_distribute(NULL, b_pile, "rrb", 1);
	}
}

void	push_a_to_b_order(t_pile **a_pile, t_pile **b_pile)
{
	t_pile	*cost_min;
	t_pile	*link;

	cost_min = cheapest_cost(*a_pile);
	link = *b_pile;
	while (link->number != cost_min->link)
		link = link->next;
	if (cost_min->position == 1 && link->position == 1)
		rotate_both(a_pile, b_pile, cost_min);
	else if (cost_min->position == 0 && link->position == 0)
		reverse_rotate_both(a_pile, b_pile, cost_min);
	set_a_pile(a_pile, cost_min);
	set_b_pile(b_pile, cost_min);
	push_distribute(a_pile, b_pile, "pb", 1);
}
