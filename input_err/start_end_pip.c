/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end_pip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:43:58 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:43:59 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

char	**start_end_pip(char **vue, t_content *cont)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (vue[i])
		i++;
	if (vue[i - 1][0] == '|')
	{
		err_stx("error sintactico\n", cont);
		free_dbl(vue);
		return (NULL);
	}
	return (vue);
}
