/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:30 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/12 17:39:18 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	len = ft_strlen(stc);
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
		new = newwhile(new, stc, pos, ft_strlen(stc));
	else
		new = newwhile(new, stc, pos, salt);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stc[256];
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
		stc[fd] = ft_strjoin(stc[fd], buff, rd);
		tam = ft_strlensalt(stc[fd]);
	}
	free(buff);
	buff = newbuff(stc[fd]);
	stc[fd] = newstc(stc[fd], tam);
	return (buff);
}

// int	main(void)
// {
// 	int	pos;
// 	int	fd;
// 	char *texto;

// 	printf("%s", get_next_line(fd));
// }