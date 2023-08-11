/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:29:16 by acaraban          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:26 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_3(const char *str)
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
