/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_redsegred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:43:50 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:43:51 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_redsegred(char **arr, t_content *cont)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '>')
		{
			if (!arr[i + 1] || ft_strchr("<>|", arr[i + 1][0]))
			{
				err_stx("error sintactico\n", cont);
				return (2);
			}
		}
		if (arr[i][0] == '<')
		{
			if (!arr[i + 1] || ft_strchr("<>|", arr[i + 1][0]))
			{
				err_stx("error sintactico\n", cont);
				return (2);
			}
		}
		i++;
	}
	return (0);
}
