/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:45:43 by udumas            #+#    #+#             */
/*   Updated: 2023/12/07 22:27:35 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../Includes/push_swap.h"

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*travel;

	if (lst == NULL)
		return ;
	travel = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		new->prec = NULL;
	}
	else
	{
		while (travel->next != NULL)
			travel = travel->next;
		travel->next = new;
		new->prec = travel;
	}
}

// int main()
// {
//     t_list * l =  NULL; t_list * l2 =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// }