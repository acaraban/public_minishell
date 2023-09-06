/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:11:19 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/05 19:47:00 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    Function to check if the options received when exit is called are numeric.
    And handle error appropiately.
    e.g. bash: exit: algo: numeric argument required
*/

void	check_options(char *options, char *cmd)
{
	int	i;

	i = 0;
	while (options[i])
	{
		if (options[0] == '-')
		{
			i++;
		}
		if (ft_isdigit(options[i]) == 1)
		{
			printf("exit\n");
			exit (0);
		}
		else
		{
			printf("exit\n");
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(ft_strjoin(ft_strjoin(ft_strjoin(cmd, ": "), options), \
						": numeric argument required\n"), 2);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	custom_exit(t_content *cont, int i)
{
	if (cont[i].full_comand[1])
	{
		check_options(cont[i].full_comand[1], cont[i].cmd);
	}
	printf("exit\n");
	exit(0);
}
