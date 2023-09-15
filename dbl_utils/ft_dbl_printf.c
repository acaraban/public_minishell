/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:50:14 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:50:15 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
	This function is to print a double pointer.
	txt: 	text before the array item
	ftxt:	text after
	sal:	0 -> ?
			1 -> ? 
*/

void	ft_dbl_printf(char *txt, char **arr, char *ftxt, int sal)
{
	int	i;

	i = 0;
	if (!sal && txt)
		ft_printf("%s", txt);
	while (arr[i])
	{
		if (sal && txt)
			ft_printf("%s", txt);
		ft_printf("%s", arr[i++]);
		if (ftxt)
			ft_printf("%s", ftxt);
	}
}
