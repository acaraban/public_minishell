/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_split_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:47 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:16:40 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_numstring_vars(int *comp, int *cles, int *i)
{
	*comp = 0;
	*cles = 0;
	*i = 0;
}

int	check_match(char *s1, int *i, t_content *cont)
{
	if (find_match(s1, *i, s1[*i]) < 0)
	{
		err_stx("error sintactico\n", cont);
		return (1);
	}
	return (0);
}
