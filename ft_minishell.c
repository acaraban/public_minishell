/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:07 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:32:19 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

t_global	*g_ggg;

void	handle_sigint(int sig)
{
	if (sig == 2)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		g_ggg->err_stat = 1;
	}
}

void	ft_minishell_bucle(int boo, char *txt, t_global *glb)
{
	while (boo)
	{
		glb->err_stat = 0;
		txt = readline("minishell> ");
		if (txt != NULL)
		{
			add_history(txt);
			ft_arg_div(txt, glb);
		}
		else
		{
			ft_free(txt);
			free_dbl(glb->env);
			ft_free (glb);
			ft_printf("exit\n");
			boo = 0;
		}
		if (boo == 1)
			ft_nrmntt_1(glb);
	}
}

/*
	ft_delete_env_oldpwd()
	This function searches for the OLDPWD environment var in the minishell program 
	(not the mac) and deletes it.
*/

//void que (){system("leaks -q minishell");}

int	main(int argc, char **argv, char **env)
{
	char		*txt;
	t_global	*glb;
	int			boo;

	(void)argc;
	(void)argv;
	txt = NULL;
	glb = NULL;
	glb = ft_init(glb, env);
	g_ggg = glb;
	boo = 1;
	ft_minishell_bucle(boo, txt, glb);
}
