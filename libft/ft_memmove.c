/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 18:00:56 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 17:01:04 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	yokse(int pos, char *k, const char *j)
{
	while (pos >= 0)
	{
		k[pos] = j[pos];
		pos--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*k;
	const char		*j;
	size_t			pos;

	k = (char *)dst;
	j = (const char *)src;
	if (k == NULL && j == NULL)
		return (NULL);
	if (k > j)
	{
		pos = len - 1;
		yokse(pos, k, j);
	}
	else
	{
		pos = 0;
		while (pos < len)
		{
			k[pos] = j[pos];
			pos++;
		}
	}
	return (k);
}
