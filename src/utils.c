/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:17:33 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 18:30:09 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_lstsize(t_pile *lst)
{
	int		i;
	t_pile	*travel;

	if (!lst)
		return (0);
	travel = lst;
	i = 0;
	while (1)
	{
		travel = travel->next;
		if (travel == lst)
			break ;
		i++;
	}
	i = i + 1;
	return (i);
}

void	ft_lstadd_front(t_pile **lst, t_pile *new)
{
	t_pile	*temp;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->prec = new;
		new->next = new;
		new->rank = 1;
	}
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		new->next = *lst;
		new->prec = temp;
		*lst = new;
	}
}

void	ft_cleanpile(t_pile **pile)
{
	t_pile	*travel;
	t_pile	*temp;

	travel = (*pile)->next;
	while (travel != *pile)
	{
		temp = travel->next;
		free(travel);
		travel = temp;
	}
	free(*pile);
	*pile = NULL;
}

t_pile	*cheapest_cost(t_pile *a_pile)
{
	t_pile	*travel;
	t_pile	*cost_min;

	travel = a_pile->next;
	cost_min = a_pile;
	while (1)
	{
		if (travel->steps < cost_min->steps)
			cost_min = travel;
		travel = travel->next;
		if (travel == a_pile)
			break ;
	}
	return (cost_min);
}

int	is_sorted(t_pile *a_pile)
{
	t_pile	*travel;
	t_pile	*travel2;

	if (a_pile == NULL)
		return (0);
	travel = a_pile;
	travel2 = a_pile->next;
	while (travel->next != a_pile)
	{
		if (travel->number > travel2->number)
			return (0);
		travel = travel->next;
		travel2 = travel2->next;
		if (travel2 == a_pile->next)
			break ;
	}
	return (1);
}
