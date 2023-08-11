/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:38:03 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 19:36:48 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	t;
	int		diff;
	size_t	tam1;
	size_t	tam2;

	tam1 = ft_strlen(s1);
	tam2 = ft_strlen(s2);
	t = 0;
	diff = 0;
	while ((t < n && diff == 0) && (t < tam1 || (t < tam2)))
	{
		diff = (unsigned char)s1[t] - (unsigned char)s2[t];
		t++;
	}
	return (diff);
}

// int main(void)
// {
// 	char j = -14;
// 	char k = -12;
// 	printf("%d", ft_strncmp(&j, &k, 0));
// 	printf("%d", strncmp(&j, &k, 0));
// }