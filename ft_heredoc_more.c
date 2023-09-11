/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:48:59 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/11 23:50:20 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

/*void	handle_sigint_here(int sig)
{
	if (sig == 2)
	{ 
		return ;
	}
}*/



void val_is_aux(t_here *here)
{
	free (here->val);
	here->val = here->aux;
	here->aux = NULL;
}



void open_and_write(t_here *here)
{
	free (here->val);
	here->fd = open(".awdrgyj123.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(here->fd, here->new, ft_strlen(here->new));
	free (here->new);
	close(here->fd);
}