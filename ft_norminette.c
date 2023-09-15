/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:54 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:48:55 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_nrmntt_1(t_global *glb)
{
	glb[0].new_stat = glb[0].err_stat;
	glb[0].err_stat = 0;
	return (0);
}

void	ft_free_cont(t_content *cont)
{
	int	i;

	i = 0;
	while (i < cont->global->num_cmd)
	{
		if (cont[i].cmd)
			ft_free(cont[i].cmd);
		if (cont[i].full_comand)
			free_dbl(cont[i].full_comand);
		if (cont[i].nfl)
			ft_free(cont[i].infile);
		if (cont[i].tfl)
			ft_free(cont[i].outfile);
		i++;
	}
	ft_free(cont);
}
