/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:44:15 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 19:44:41 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str_end;

	str_end = (char *)s + ft_strlen(s);
	while (str_end > s && *str_end != (char)c)
		str_end--;
	if (*str_end == (char)c)
		return (str_end);
	return (NULL);
}

// int	main(void)
// {
// 	char j = 'j';
// 	char h[] = "agsdjfasdfnjadfgag";
// 	printf("%s\n", strrchr(h, j));
// 	printf("%s\n", h);

// 	char a = 'j';
// 	char s[] = "adfadsffjasdfajdfas";
// 	printf("%s\n", ft_strrchr(s, a));
// 	printf("%s", s);
// }