/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:00:17 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/19 18:59:45 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	int	num;

	num = 0;
	if ((a >= 0 && a <= 127))
	{
		num = 1;
	}
	return (num);
}

// int main(void)
// {
// 	printf("%d",isascii(7));
// 	printf("%d",ft_isascii(7));
// }