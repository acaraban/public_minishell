/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:49:51 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 13:28:00 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	same_char_across(char *str, int pos_ini, int pos_fin, char c)
{
	int	i;
	int	diff;
	int	count;

	i = 0;
	count = 0;
	diff = (pos_fin - pos_ini) + 1;
	while ((i <= pos_fin) && str[i])
	{
		while (i < pos_ini)
			i++;
		while (i <= pos_fin && count < diff)
		{
			while (str[i] == c)
			{
				count++;
				i++;
			}
			i++;
		}
		if (count == diff)
			return (0);
		i++;
	}
	return (1);
}
