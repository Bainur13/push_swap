/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:48:55 by udumas            #+#    #+#             */
/*   Updated: 2024/01/31 19:09:50 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

// attribuer les caracteristique du lien a la structure du node
void	test_link(t_pile **node, t_pile *link)
{
	if ((*node)->link < link->number)
	{
		(*node)->link = link->number;
		(*node)->linkrank = link->rank;
		(*node)->linkposition = link->position;
	}
}

// calculer le nombre de coup pour chaque node, selon sa position
// et celle de son lien
void	calculate_steps(t_pile **a_pile, int size_b)
{
	int		size_a;
	t_pile	*travel;

	travel = *a_pile;
	size_a = ft_lstsize(*a_pile);
	while (1)
	{
		travel->steps = travel->rank;
		if (travel->position == 0)
			travel->steps = size_a - travel->rank;
		if (travel->linkposition == 1)
			travel->steps += travel->linkrank;
		else
			travel->steps += size_b - travel->linkrank;
		travel = travel->next;
		if (travel == *a_pile)
			break ;
	}
}

// attribuer le lien a chaque node de la pile a
void	attribuate_link(t_pile **a_pile, t_pile **b_pile)
{
	t_pile	*travel_a;
	t_pile	*travel_b;

	travel_a = *a_pile;
	travel_b = *b_pile;
	while (1)
	{
		travel_a->link = LONG_MIN;
		while (1)
		{
			if (travel_b->number < travel_a->number)
				test_link(&travel_a, travel_b);
			travel_b = travel_b->next;
			if (travel_b == *b_pile)
				break ;
		}
		if (travel_a->link == LONG_MIN)
			test_link(&travel_a, get_biggest_number(b_pile));
		travel_a = travel_a->next;
		if (travel_a == *a_pile)
			break ;
	}
}

// push 2 elements de la pile a vers la pile b sans distinction
void	push_start(t_pile **a_pile, t_pile **b_pile)
{
	if (ft_lstsize(*a_pile) > 3)
		push_distribute(a_pile, b_pile, "pb", 1);
	if (ft_lstsize(*a_pile) > 3)
		push_distribute(a_pile, b_pile, "pb", 1);
	return ;
}

void	particular_case(t_pile **a_pile, int status)
{
	t_pile	*travel;

	if (status == 0)
	{
		travel = (*a_pile)->next;
		if ((*a_pile)->number > travel->number)
			swap_distribute(a_pile, NULL, "sa", 1);
	}
	else
	{
		if (get_biggest_number(a_pile)->rank != 2)
		{
			if (get_biggest_number(a_pile)->number != (*a_pile)->number)
				reverse_rotate_distribute(a_pile, NULL, "rra", 1);
			else
				rotate_distribute(a_pile, NULL, "ra", 1);
		}
		if (find_smallest_number(a_pile) != *a_pile
			|| get_biggest_number(a_pile) != ft_lstlast(*a_pile))
			swap_distribute(a_pile, NULL, "sa", 1);
	}
}
