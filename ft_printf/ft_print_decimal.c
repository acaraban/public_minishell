/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:27 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/12 17:39:49 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int j)
{
	int		tam;
	char	*lk;

	lk = ft_itoa(j);
	tam = print_string(lk);
	free(lk);
	return (tam);
}

int	print_ent(int j)
{
	int		tam;
	char	*lk;

	lk = ft_itoa(j);
	tam = print_string(lk);
	free(lk);
	return (tam);
}

int	print_dec(unsigned int j)
{
	static int		tam;
	unsigned int	lk;

	tam = 0;
	lk = j;
	if (j >= 10)
	{
		print_dec(j / 10);
		lk %= 10;
	}
	tam++;
	printchar(lk + '0');
	return (tam);
}
