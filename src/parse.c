/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:18:24 by udumas            #+#    #+#             */
/*   Updated: 2024/02/02 15:35:02 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_pile	*parse(t_pile **init, char **av, int size)
{
	int	i;
	int	count;
	int	temp;

	i = 1;
	while (size > 0)
	{
		count = 0;
		while (1)
		{
			temp = create_chain_list(init, &av[i][count]);
			size--;
			if (temp == 0)
			{
				i++;
				break ;
			}
			else if (temp == -1 && ft_lstsize(*init) > 0)
				ft_cleanpile(init);
			if (temp == -1)
				return (NULL);
			count = count + temp;
		}
	}
	return (*init);
}

int	create_chain_list(t_pile **start, char *str)
{
	t_pile	*new_node;
	int		status;

	new_node = malloc(sizeof(t_pile));
	if (new_node == NULL)
		return (-1);
	ft_lstadd_back(start, new_node);
	status = ft_extract(&new_node->number, str);
	if (status == -1)
	{
		ft_cleanpile(start);
	}
	return (status);
}

int	ft_extract(long *number, char *str)
{
	int		i;
	long	temp;
	int		isneg;

	isneg = 1;
	i = 0;
	temp = 0;
	if (!str)
		return (-1);
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while ((ft_isdigit(str[i], str[i + 1]) == 1) && str[i] != '\0')
		temp = temp * 10 + (str[i++] - '0');
	while (ft_isspace(str[i]) == 1)
		i++;
	if ((temp * isneg) > INT_MAX || (temp * isneg) < INT_MIN)
		return (-1);
	if (str[i] == '\0')
		return (*number = temp * isneg, 0);
	return (*number = temp * isneg, i);
}
