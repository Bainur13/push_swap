/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_by_groups.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:12:24 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 18:59:55 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	push_by_groups(t_pile **a_pile, t_pile **b_pile)
{
	while (ft_lstsize(*a_pile) > 3)
	{
		send_to_b_rotate(a_pile, b_pile);
	}
}

int	smallest_group_check(t_pile *a_pile)
{
	int		smallest;
	t_pile	*travel;

	travel = a_pile;
	smallest = a_pile->group;
	while (1)
	{
		if (travel->group < smallest)
			smallest = travel->group;
		travel = travel->next;
		if (travel == a_pile)
			break ;
	}
	return (smallest);
}

void	send_to_b_rotate(t_pile **a_pile, t_pile **b_pile)
{
	int	smallest_group;

	smallest_group = smallest_group_check(*a_pile);
	while ((*a_pile)->group > smallest_group + 1)
		rotate_distribute(a_pile, b_pile, "ra", 1);
	if ((*a_pile)->group == smallest_group + 1)
	{
		push_distribute(a_pile, b_pile, "pb", 1);
		if ((*a_pile)->group > smallest_group + 1)
			rotate_distribute(a_pile, b_pile, "rr", 1);
		else
			rotate_distribute(a_pile, b_pile, "rb", 1);
	}
	if ((*a_pile)->group == smallest_group)
		push_distribute(a_pile, b_pile, "pb", 1);
}
