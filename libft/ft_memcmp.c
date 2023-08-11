/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:03:57 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 19:58:46 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*sour;

	if (num == 0)
		return (0);
	dest = (unsigned char *)ptr1;
	sour = (unsigned char *)ptr2;
	i = 0;
	while (*sour == *dest && ++i < num)
	{
		sour++;
		dest++;
	}
	return (*dest - *sour);
}

// int main(void)
// {
// 	char l[] = "hola mundo";
// 	char j[] = "hola mlndo";
// 	printf("%d\n", strncmp(l, j, 10));
// 	printf("%d\n", memcmp(l, j, 10));
// 	printf("%d", ft_memcmp(l, j, 10));

// 	return (0);
// }