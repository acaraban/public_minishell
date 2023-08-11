/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:57:47 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 17:02:23 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	*chr;

	chr = (unsigned char *)str;
	i = 0;
	while (i < (int)n)
	{
		if (chr[i] == (unsigned char)c)
		{
			return ((void *)&chr[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char cadena[] = "erase una vez...";
// 	printf("%s", ft_memchr(cadena, 'a', 25));
// }