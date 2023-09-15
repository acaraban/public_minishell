/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_nolstpar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:43:42 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:43:43 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_nolstpar(char *txt, int pos, t_content *cont)
{
	int	i;

	i = 0;
	while (txt[i + pos] != ')' && txt[i + pos])
		i++;
	if (txt[i + pos] != ')')
	{
		err_stx("error sintactico\n", cont);
		return (0);
	}
	return (i);
}
