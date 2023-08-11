/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:25:56 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 19:52:40 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		start = i;
	if (i - start < len)
		len = i - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		ft_memcpy(str, (void *)&s[start], len);
		str[len] = '\0';
	}
	return (str);
}
