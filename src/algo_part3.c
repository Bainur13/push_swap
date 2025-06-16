/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:59 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 18:59:21 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_pile	*cheapest_cost2(t_pile *b_pile)
{
	t_pile	*travel;
	t_pile	*cost_min;
	int		biggest_group;

	biggest_group = get_biggest_group(b_pile);
	travel = b_pile->next;
	while (travel->group != biggest_group)
		travel = travel->next;
	cost_min = travel;
	travel = b_pile;
	while (1)
	{
		if (travel->steps < cost_min->steps && (travel->group == biggest_group))
			cost_min = travel;
		travel = travel->next;
		if (travel == b_pile)
			break ;
	}
	return (cost_min);
}

void	rotate_both2(t_pile **a_pile, t_pile **b_pile, t_pile *to_move)
{
	t_pile	*link;

	link = *a_pile;
	while (link->number != to_move->link)
		link = link->next;
	while (1)
	{
		if (to_move->rank == 0 || link->rank == 0)
			break ;
		rotate_distribute(a_pile, b_pile, "rr", 1);
	}
}

void	reverse_rotate_both2(t_pile **a_pile, t_pile **b_pile, t_pile *to_move)
{
	t_pile	*link;

	link = *a_pile;
	while (link->number != to_move->link)
		link = link->next;
	while (1)
	{
		if (to_move->rank == 0 || link->rank == 0)
			break ;
		reverse_rotate_distribute(a_pile, b_pile, "rrr", 1);
	}
}

void	set_a_pile3(t_pile **a_pile, t_pile *to_move)
{
	int		size_a;
	t_pile	*link;

	link = *a_pile;
	while (link->number != to_move->link)
		link = link->next;
	size_a = ft_lstsize(*a_pile);
	while (link->rank != 0)
	{
		if (link->position == 1)
			rotate_distribute(a_pile, NULL, "ra", 1);
		else
			reverse_rotate_distribute(a_pile, NULL, "rra", 1);
	}
}

void	set_b_pile2(t_pile **b_pile, t_pile *to_move)
{
	int	size_b;

	size_b = ft_lstsize(*b_pile);
	while (to_move->rank != 0)
	{
		if (to_move->position == 1)
			rotate_distribute(NULL, b_pile, "rb", 1);
		else
			reverse_rotate_distribute(NULL, b_pile, "rrb", 1);
	}
}
