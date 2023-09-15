/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:10:37 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 12:49:55 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	custom_echo(t_content *cont, int i)
{
	int	n;
	int	total;

	n = 0;
	while (cont[i].full_comand[n])
		n++;
	total = n;
	n = 2;
	if (cont[i].full_comand[2] == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		while (cont[i].full_comand[n])
		{
			if (n == 2 || n == total)
				ft_printf("%s", cont[i].full_comand[n]);
			else
				ft_printf(" %s", cont[i].full_comand[n]);
			n++;
		}
	}
}
