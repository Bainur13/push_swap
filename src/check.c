/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:13:24 by udumas            #+#    #+#             */
/*   Updated: 2024/02/02 15:08:32 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	count_numbers(char **av)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((ft_isdigit(av[i][j], av[i][j + 1]) && (ft_isspace_minus(av[i][j
							+ 1]) || av[i][j + 1] == '\0')))
				count++;
		}
	}
	return (count);
}

int	is_digit_space(char **av)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (av[++i])
	{
		if (av[i][0] == '\0')
			return (0);
		j = -1;
		while (av[i][++j])
		{
			if (!(ft_isdigit(av[i][j], av[i][j + 1])
					|| (ft_isspace_minus(av[i][j]))))
				return (0);
			if (av[i][j] == '-' && av[i][j + 1] == '-')
				return (0);
		}
	}
	return (1);
}

int	check_double(t_pile **init)
{
	t_pile	*travel;
	t_pile	*temp;

	temp = *init;
	while (temp->next != (*init))
	{
		travel = temp->next;
		while (travel != *init)
		{
			if (travel->number == temp->number)
				return (ft_cleanpile(init), 0);
			travel = travel->next;
		}
		temp = temp->next;
	}
	return (1);
}

int	check_pile(t_pile *a_pile)
{
	int		numb;
	t_pile	*travel;
	t_pile	*temp;

	numb = 0;
	if (a_pile == NULL)
		return (0);
	temp = a_pile;
	travel = a_pile->next;
	while (temp->number < travel->number)
	{
		numb++;
		temp = temp->next;
		travel = travel->next;
		if (travel == a_pile)
			return (ft_cleanpile(&a_pile), 0);
	}
	set_rank(a_pile);
	set_prec(a_pile);
	return (1);
}
