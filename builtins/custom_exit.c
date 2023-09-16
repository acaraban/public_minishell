/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:11:19 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/16 13:21:19 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
    Function to check if the options received when exit is called are numeric.
    And handle error appropiately.
    e.g. bash: exit: algo: numeric argument required
*/

int	check_options(t_content *cont, int i)
{
	int	n;

	n = 0;
	if (cont[i].full_comand[2])
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(ft_strjoin(ft_strjoin(cont[i].cmd, ": "), ": too many arguments\n"), 2);
		return (2);
	}
	while (cont[i].full_comand[1][n])
	{
		if (cont[i].full_comand[1][0] == '-')
			n++;
		if (ft_isdigit(cont[i].full_comand[1][n]) == 1)
		{
			printf("exit\n");
			cont->global->err_stat = ft_atoi(cont[i].full_comand[1]);
			exit (cont->global->err_stat);
		}
		else
		{
			printf("exit\n");
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(ft_strjoin(ft_strjoin(ft_strjoin(cont[i].cmd, ": "), cont[i].full_comand[1]), ": numeric argument required\n"), 2);
			exit (EXIT_FAILURE);
		}
		n++;
	}
	return (0);
}

void	custom_exit(t_content *cont, int i, t_pipes *fds)
{
	if (cont[i].full_comand[1])
	{
		if (check_options(cont, i) == 2)
		{
			return ;
		}
	}
	printf("exit\n");
	ft_free(fds);
	exit(0);
}
