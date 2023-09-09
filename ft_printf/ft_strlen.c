/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:29:16 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/09 22:47:37 by msintas-         ###   ########.fr       */
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
