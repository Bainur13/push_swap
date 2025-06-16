/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:35:19 by udumas            #+#    #+#             */
/*   Updated: 2024/01/03 12:29:23 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	set_prec(t_pile *to_set)
{
	t_pile	*travel;
	t_pile	*temp;

	if (to_set == NULL)
		return ;
	travel = to_set->next;
	temp = to_set;
	while (1)
	{
		travel->prec = temp;
		temp = travel;
		travel = travel->next;
		if (travel == to_set->next)
			break ;
	}
	travel->prec = temp;
}

void	set_rank(t_pile *to_set)
{
	int		i;
	int		half;
	t_pile	*travel;

	if (to_set == NULL)
		return ;
	i = 0;
	half = ft_lstsize(to_set) / 2;
	travel = to_set;
	while (1)
	{
		travel->rank = i;
		if (i <= half)
			travel->position = 1;
		else
			travel->position = 0;
		i++;
		travel = travel->next;
		if (travel == to_set)
			break ;
	}
	return ;
}

t_pile	*find_smallest_number(t_pile **pile)
{
	t_pile	*travel;
	t_pile	*smallest;

	travel = *pile;
	smallest = *pile;
	while (travel->next != *pile)
	{
		if (travel->number < smallest->number)
			smallest = travel;
		travel = travel->next;
	}
	if (travel->number < smallest->number)
		smallest = travel;
	return (smallest);
}

t_pile	*get_biggest_number(t_pile **pile)
{
	t_pile	*travel;
	t_pile	*biggest;

	travel = *pile;
	biggest = *pile;
	while (travel->next != *pile)
	{
		if (travel->number > biggest->number)
			biggest = travel;
		travel = travel->next;
	}
	if (travel->number > biggest->number)
		biggest = travel;
	return (biggest);
}
