/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:18:18 by acaraban          #+#    #+#             */
/*   Updated: 2022/08/18 18:58:58 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cond(const char *str, int pos, va_list list)
{
	int	tam;

	tam = 0;
	if (str[pos] == 'c')
		tam = printchar(va_arg(list, int));
	else if (str[pos] == 's')
		tam = print_string(va_arg(list, char *));
	else if (str[pos] == 'd')
		tam = print_int(va_arg(list, int));
	else if (str[pos] == 'i')
		tam = print_ent(va_arg(list, unsigned int));
	else if (str[pos] == 'u')
		tam = print_dec(va_arg(list, unsigned int));
	else if (str[pos] == 'x')
		hex(va_arg(list, unsigned int), &tam);
	else if (str[pos] == 'X')
		hexup(va_arg(list, unsigned int), &tam);
	else if (str[pos] == '%')
		tam = printchar('%');
	else if (str[pos] == 'p')
		tam = ptrr(va_arg(list, unsigned long long), tam);
	else
		tam = printchar(*str);
	return (tam);
}

int	ft_printf(char const *j, ...)
{
	int		pos;
	va_list	list;
	int		tam;

	pos = 0;
	tam = 0;
	if (j[pos] == '\0')
		return (0);
	va_start(list, j);
	while (j[pos])
	{
		if (j[pos] == '%')
		{
			pos++;
			tam = tam + ft_cond(j, pos, list) - 1;
		}
		else
			write(1, &j[pos], 1);
		pos++;
		tam++;
	}
	va_end(list);
	return (tam);
}
