/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_dobcom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:43:28 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:43:29 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_dobcom(char *txt, t_content *cont)
{
	int	i;

	i = 0;
	while (txt[i])
	{
		if (txt[i] == '\'' || txt[i] == '\"')
		{
			if (find_match(txt, i, txt[i]) < 0)
			{
				err_stx("error sintactico\n", cont);
				return (-1);
			}
			i += find_match(txt, i, txt[i]);
		}
		i++;
	}
	return (1);
}
