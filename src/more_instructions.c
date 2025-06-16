/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:59:51 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 19:53:05 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rotate(t_pile **to_rotate)
{
	if (*to_rotate == NULL)
		return ;
	(*to_rotate) = (*to_rotate)->next;
	set_rank(*to_rotate);
	set_prec(*to_rotate);
}

void	reverse_rotate(t_pile **to_rotate)
{
	if (*to_rotate == NULL)
		return ;
	(*to_rotate) = (*to_rotate)->prec;
	set_rank(*to_rotate);
	set_prec(*to_rotate);
}

void	rotate_distribute(t_pile **a_list, t_pile **b_list, char *instruct,
							int checker)
{
	if (checker == 1)
		ft_printf("%s\n", instruct);
	if (!ft_strncmp(instruct, "ra", 3))
		rotate(a_list);
	else if (!ft_strncmp(instruct, "rb", 3))
		rotate(b_list);
	else if (!ft_strncmp(instruct, "rr", 3))
	{
		rotate(a_list);
		rotate(b_list);
	}
	return ;
}

void	reverse_rotate_distribute(t_pile **a_list, t_pile **b_list,
		char *instruct, int checker)
{
	if (checker == 1)
		ft_printf("%s\n", instruct);
	if (!ft_strncmp(instruct, "rra", 4))
		reverse_rotate(a_list);
	else if (!ft_strncmp(instruct, "rrb", 4))
		reverse_rotate(b_list);
	else if (!ft_strncmp(instruct, "rrr", 4))
	{
		reverse_rotate(a_list);
		reverse_rotate(b_list);
	}
	return ;
}
