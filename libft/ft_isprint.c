/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:06:21 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/19 19:00:26 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	int	num;

	num = 0;
	if ((a >= 32 && a <= 126))
	{
		num = 1;
	}
	return (num);
}

// int main(void)
// {
// 	printf("%d",isprint(31));
// 	printf("%d",ft_isprint(31));
// }