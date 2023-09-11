/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:48:59 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/11 23:53:23 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>



void bucle_here_aux(t_here *here)
{
	while (here->val[here->r])
	{
		here->aux[here->r] = here->val[here->r];
		here->r++;
	}
	here->aux[here->r] = '\n';
}

void free_and_copy(t_here *here)
{
	free (here->val);
	here->val = ft_strdup(here->aux);
	free (here->aux);
	if (here->new)
		here->aux = ft_strjoin(here->new, here->val);
	else
		here->aux = ft_strdup(here->val);
	free (here->new);
	here->new = ft_strdup(here->aux);
	free (here->aux);
	here->r = 0;
}

void free_no_val(t_here *here)
{
	free(here->val);
	free (here->new);
	ft_printf("exit\n");
}

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