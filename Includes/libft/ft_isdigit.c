/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udumas <udumas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:41:02 by udumas            #+#    #+#             */
/*   Updated: 2023/11/06 11:41:02 by udumas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c, int c_plus)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-' && (c_plus >= '0' && c <= '9'))
		return (1);
	return (0);
}
// int	main(void)
// {
// 	char str[8] = "abcdd";
// 	printf("%d", ft_isdigit(str[3]));
// 	return (0);
// }