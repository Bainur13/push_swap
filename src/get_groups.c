/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_groups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:55:42 by udumas            #+#    #+#             */
/*   Updated: 2024/01/31 14:34:32 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	initialize(t_pile **a_pile)
{
	t_pile	*travel;

	travel = *a_pile;
	while (1)
	{
		travel->index = 0;
		travel = travel->next;
		if (travel == *a_pile)
			break ;
	}
	while (1)
	{
		travel->group = 0;
		travel = travel->next;
		if (travel == *a_pile)
			break ;
	}
}

void	add_index_groups(t_pile **a_pile)
{
	t_pile	*travel;
	t_pile	*smallest;
	int		index;
	int		size_a;

	initialize(a_pile);
	size_a = ft_lstsize(*a_pile);
	travel = *a_pile;
	index = 1;
	size_a = ft_lstsize(*a_pile);
	while (1)
	{
		smallest = smallest_no_index(*a_pile);
		if (smallest == NULL)
			break ;
		smallest->index = index;
		smallest->group = get_groups(smallest->index, size_a);
		index++;
	}
}

t_pile	*smallest_no_index(t_pile *a_pile)
{
	t_pile	*travel;
	t_pile	*smallest;

	travel = a_pile;
	while (1)
	{
		if (travel->index == 0)
		{
			smallest = travel;
			break ;
		}
		travel = travel->next;
		if (travel == a_pile)
			return (NULL);
	}
	while (1)
	{
		if (travel->index == 0 && travel->number < smallest->number)
			smallest = travel;
		travel = travel->next;
		if (travel == a_pile)
			break ;
	}
	return (smallest);
}

int	get_groups(int index, int size_a)
{
	int	groups;
	int	divider;
	int	groups_size;

	groups_size = 1;
	groups = 0;
	if (size_a < 250)
		return (0);
	else
		divider = 6;
	while (groups_size <= divider)
	{
		if (index > (size_a / divider) * (groups_size - 1))
			groups = groups_size;
		groups_size++;
	}
	return (groups);
}
