/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:01:28 by acaraban          #+#    #+#             */
/*   Updated: 2022/08/04 14:25:35 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str)
{
	int	pos;
	int	tam;

	pos = 0;
	tam = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		tam = 6;
	}
	else
	{
		while (str[pos])
		{
			printchar(str[pos]);
			pos++;
			tam++;
		}
	}
	return (tam);
}
