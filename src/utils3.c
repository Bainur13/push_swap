/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:19:56 by udumas            #+#    #+#             */
/*   Updated: 2024/01/31 17:41:27 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_pile	*ft_lstlast(t_pile *lst)
{
	t_pile	*travel;

	if (!lst)
		return (NULL);
	travel = lst;
	while (travel->next != lst)
		travel = travel->next;
	return (travel);
}

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*travel;

	if (lst == NULL)
		return ;
	travel = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		new->prec = *lst;
		new->next = *lst;
		new->rank = 1;
	}
	else
	{
		while (travel->next != *lst)
			travel = travel->next;
		travel->next = new;
		new->prec = travel;
		new->next = *lst;
		(*lst)->prec = new;
	}
}

int	get_biggest_group(t_pile *pile)
{
	int		group;
	t_pile	*travel;

	travel = pile;
	group = 0;
	while (1)
	{
		if (travel->group > group)
			group = travel->group;
		travel = travel->next;
		if (travel == pile)
			break ;
	}
	return (group);
}

void	test_link2(t_pile **node, t_pile *link)
{
	if ((*node)->link > link->number)
	{
		(*node)->link = link->number;
		(*node)->linkrank = link->rank;
		(*node)->linkposition = link->position;
	}
}

t_pile	*check_and_parse(char **av, int ac)
{
	int		size;
	t_pile	*init;

	size = count_numbers(&av[1]);
	init = NULL;
	if (ac == 1)
		return (NULL);
	if (is_digit_space(&av[1]) == 0 || size == 0 || parse(&init, av,
			size) == NULL || check_double(&init) == 0)
		write(2, "Error\n", 6);
	return (init);
}
