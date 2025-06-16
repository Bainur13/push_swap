/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:36:15 by udumas            #+#    #+#             */
/*   Updated: 2024/01/04 19:52:47 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap(t_pile **a_pile, char *instruct, int checker)
{
	t_pile	*second;
	int		temp;

	temp = 0;
	if (ft_lstsize(*a_pile) < 2)
		return ;
	if (checker == 1)
		ft_printf("%s\n", instruct);
	second = (*a_pile)->next;
	temp = second->number;
	second->number = (*a_pile)->number;
	(*a_pile)->number = temp;
	set_rank(*a_pile);
	set_prec(*a_pile);
}

void	push(t_pile **push, t_pile **receive, char *instruct, int checker)
{
	t_pile	*temp;

	if (ft_lstsize(*push) == 0)
		return ;
	if (checker == 1)
		ft_printf("%s\n", instruct);
	if (ft_lstsize(*push) == 1)
	{
		ft_lstadd_front(receive, *push);
		*push = NULL;
		set_prec(*receive);
		return ;
	}
	temp = (*push)->prec;
	temp->next = (*push)->next;
	temp = (*push)->next;
	temp->prec = (*push)->prec;
	ft_lstadd_front(receive, *push);
	*push = temp;
}

void	swap_distribute(t_pile **a_list, t_pile **b_list, char *instruct,
						int checker)
{
	if (!ft_strncmp(instruct, "sa", 3))
		swap(a_list, instruct, checker);
	else if (!ft_strncmp(instruct, "sb", 3))
		swap(b_list, instruct, checker);
	else if (!ft_strncmp(instruct, "ss", 3))
	{
		swap(a_list, "", checker);
		swap(b_list, "", checker);
		ft_printf("ss");
	}
	return ;
}

void	push_distribute(t_pile **a_list, t_pile **b_list, char *instruct,
						int checker)
{
	if (!ft_strncmp(instruct, "pa", 3))
		push(b_list, a_list, instruct, checker);
	else if (!ft_strncmp(instruct, "pb", 3))
		push(a_list, b_list, instruct, checker);
	set_prec(*a_list);
	set_prec(*b_list);
	set_rank(*a_list);
	set_rank(*b_list);
	return ;
}
