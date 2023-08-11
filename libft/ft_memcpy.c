/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:25:35 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 17:02:35 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int	pos;

	pos = n - 1;
	if (!n || (unsigned char *)(str1) == (unsigned char *)(str2))
	{
		return ((unsigned char *)str1);
	}
	while (pos > -1)
	{
		*(unsigned char *)(str1 + pos) = *(unsigned char *)(str2 + pos);
		pos--;
	}
	return ((unsigned char *)str1);
}

// int	main(void)
// {
// 	char string[] = "stackoverflow";
// 	char *third, *fourth;
// 	third = string;
// 	fourth = string;

// 	puts(string);
// 	ft_memcpy(third + 5, third, 7);
// 	puts(third);
// 	memmove(fourth + 5, fourth, 7);
// 	puts(fourth);
// 	return (0);
// }