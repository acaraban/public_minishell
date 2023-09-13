/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:55:57 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/12 17:09:01 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, len);
	return (s2);
}

// int main(void)
// {
// 	char io[] = "askdfhalkdfh";

// 	char *lk = ft_strdup(io);

// 	printf("%s", lk);
// }