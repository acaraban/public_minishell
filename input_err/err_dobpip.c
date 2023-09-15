/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_dobpip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:43:38 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:43:39 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_dobpip(char *txt, int i, t_content *cont)
{
	if (txt[i] == '|' && txt[i + 1] == '|')
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	return (0);
}
