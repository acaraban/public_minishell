/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:53 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/08 14:07:11 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		i;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	s3 = (char *)malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s3[len_s1 + i] = s2[i];
		i++;
	}
	s3[len_s1 + i] = '\0';
	return (s3);
}
