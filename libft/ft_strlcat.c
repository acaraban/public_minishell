/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:48:24 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 17:30:27 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	unsigned long int	c;
	unsigned long int	d;
	unsigned long int	f;
	unsigned long int	h;

	c = ft_strlen(dest);
	d = ft_strlen(src);
	f = nb;
	h = f;
	if (c < nb)
		f = c;
	nb -= ft_strlen(dest);
	if (h > c)
	{
		while (*src != '\0' && nb > 1)
		{
			dest[c] = *src;
			c++;
			src++;
			nb--;
		}
		dest[c] = '\0';
	}
	dest[c] = '\0';
	return (f + d);
}

// int main(void)
// {
// 	char j[40] = "hola mundo";
// 	char h[] = ", mundo";
// 	printf("%zu", ft_strlcat(j, h, 40));
// 	printf("%s\n", j);
// 	char o[40] = "hola mundo";
// 	char p[] = ", mundo";
// 	printf("%zu", strlcat(o, p, 40));
// 	printf("%s", o);
// }