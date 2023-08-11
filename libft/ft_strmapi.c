/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:03:21 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/21 17:39:57 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped;

	mapped = (char *)malloc(ft_strlen((char *)s) + 1);
	if (s == NULL)
		return (NULL);
	if (!(mapped))
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(mapped + i) = (*f)(i, *(s + i));
		i++;
	}
	*(mapped + i) = '\0';
	return (mapped);
}

// int main(void)
// {
// 	char j[] = "12asdsfhljgGKHKJHghggkgjjhgjggGHJKJsd";
// 	char h[50];
// 	printf("%s",ft_strmapi(j, ft_tolower));
// }