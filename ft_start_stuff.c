/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:49:26 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 13:33:21 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    When minishell starts, environment variables should not include OLDPWD.
    Function to search for it and delete it.
    Before deletion and modifing all other item indexes, reorder to send
    After that modify all the other items indexes to make the array shorter.
*/

void	ft_delete_env_oldpwd(char **environment)
{
	int	index;
	int	j;

	j = 0;
	while (environment[j])
	{
		if (ft_strncmp(environment[j], "OLDPWD", 6) == 0)
		{
			ft_free(environment[j]);
			index = j;
		}
		j++;
	}
	while (environment[index])
	{
		environment[index] = environment[index + 1];
		index++;
	}
}

void	ft_free(void *ttt)
{
	free(ttt);
	ttt = NULL;
}
