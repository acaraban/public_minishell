/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:43:45 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:43:46 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_red(int i, char *txt, t_content *cont)
{
	int		h;
	char	a;
	char	b;

	a = '<';
	b = '>';
	h = 0;
	while (txt[i + h] == a || txt [i + h] == b)
		h++;
	if (h > 2)
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	return (0);
}
