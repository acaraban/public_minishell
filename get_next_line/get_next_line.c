/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:30 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/12 17:39:18 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*newwhile(char *new, char *stc, size_t pos, size_t len)
{
	new = (char *)ft_calloc_2(sizeof(char), len + 1);
	if (!new)
		return (NULL);
	while (pos < len)
	{
		new[pos] = stc[pos];
		pos++;
	}
	return (new);
}

char	*newstc(char *stc, int tam)
{
	int		pos;
	int		len;
	char	*new;

	pos = 0;
	len = ft_strlen_2(stc);
	new = (char *)ft_calloc_2(sizeof(char), len - tam + 1);
	if (tam == 0)
	{
		free(stc);
		free(new);
		return (0);
	}
	while (pos + tam < len)
	{
		new[pos] = stc[pos + tam];
		pos++;
	}
	free(stc);
	return (new);
}

char	*newbuff(char *stc)
{
	char	*new;
	size_t	pos;
	int		salt;

	pos = 0;
	new = NULL;
	salt = ft_strlensalt(stc);
	if (!stc[0])
		return (NULL);
	if (salt == 0)
	{
		new = newwhile(new, stc, pos, ft_strlen_2(stc));
	}
	else
	{
		new = newwhile(new, stc, pos, salt);
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stc;
	char		*buff;
	int			rd;
	int			tam;

	if (fd < 0)
		return (0);
	buff = (char *)ft_calloc_2(sizeof(char), BUFFER_SIZE + 1);
	rd = BUFFER_SIZE;
	tam = 0;
	while (rd == BUFFER_SIZE && tam == 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		stc = ft_strjoin_m(stc, buff, rd);
		tam = ft_strlensalt(stc);
	}
	free(buff);
	buff = newbuff(stc);
	stc = newstc(stc, tam);
	return (buff);
}

// int	main(void)
// {
// 	int		pos;
// 	int		fd;
// 	char	*str;

// 	pos = 0;
// 	fd = open("archivo.txt", O_RDONLY);
// 	while (pos < 1)
// 	{
// 		printf("%s", get_next_line(fd));
// 		pos++;
// 	}
// 	printf("\n");
// 	system("leaks -q a.out");
// }
