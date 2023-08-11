/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:34:53 by acaraban          #+#    #+#             */
/*   Updated: 2023/06/16 20:02:54 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdlib.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned long int	pos;
	unsigned char		*ptr;

	pos = 0;
	ptr = (unsigned char *)s;
	while (pos < n)
	{
		ptr[pos] = '\0';
		pos++;
	}
	return (s);
}

void	*ft_calloc_2(size_t number, size_t size)
{
	void	*dest;

	dest = (void *)malloc(number * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, number * size);
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlensalt(const char *str)
{
	unsigned long int	num;

	num = 0;
	if (!str)
		return (0);
	while (str[num] != 0 && str[num] != '\n')
		num++;
	if (str[num] == 0)
		return (0);
	num++;
	return (num);
}

char	*ft_strjoin(char *left_str, char *buff, int rd)
{
	int		i;
	int		j;
	char	*str;

	if (!left_str)
		left_str = (char *)ft_calloc_2(1, sizeof(char));
	if (!left_str || !buff)
		return (NULL);
	str = ft_calloc_2(sizeof(char), (ft_strlen(left_str) + \
	ft_strlen(buff)) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0' && j < rd)
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}
