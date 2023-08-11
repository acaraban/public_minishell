/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:29:16 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/24 17:30:21 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned long int	tam;

	tam = 0;
	while (*str != '\0')
	{
		tam++;
		str++;
	}
	return (tam);
}

// int main(void)
// {
// 	char kj[] = "ffadfkkjhafd";

// 	printf("%lu", strlen(kj));
// }
