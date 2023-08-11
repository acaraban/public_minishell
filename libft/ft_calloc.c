/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:55:51 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 19:42:24 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*dest;

	dest = (void *)malloc (number * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, number * size);
	return (dest);
}

// int main(void)
// {
// 	char *c = (char *)ft_calloc(5, sizeof(char));
// 	c = "asdfg";
// 	printf("%s", c);
// }