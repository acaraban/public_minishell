/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:39:45 by acaraban          #+#    #+#             */
/*   Updated: 2023/06/16 20:07:36 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pointer_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	hex(unsigned int num, int *tam)
{
	if (num >= 16)
	{
		hex(num / 16, tam);
		hex(num % 16, tam);
	}
	else
	{
		*tam = *tam + 1;
		if (num <= 9)
			printchar((num + '0'));
		else
			printchar((num - 10 + 'a'));
	}
}

void	hexup(unsigned int num, int *tam)
{
	if (num >= 16)
	{
		hexup(num / 16, tam);
		hexup(num % 16, tam);
	}
	else
	{
		*tam = *tam + 1;
		if (num <= 9)
			printchar((num + '0'));
		else
			printchar((num - 10 + 'A'));
	}
}

void	putptr(unsigned long long num)
{
	if (num >= 16)
	{
		putptr(num / 16);
		putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			printchar((num + '0'));
		else
			printchar((num - 10 + 'a'));
	}
}

int	ptrr(unsigned long long n, int h)
{
	write(1, "0x", 2);
	h += 2;
	if (n == 0)
	{
		write(1, "0", 1);
		h += 1;
	}
	else
	{
		putptr(n);
		h += ft_pointer_len(n);
	}
	return (h);
}
