/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_red.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:44:03 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:44:04 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	start_end_red(char **vue, t_content *cont)
{
	if (vue[0][0] == '|')
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	return (0);
}
