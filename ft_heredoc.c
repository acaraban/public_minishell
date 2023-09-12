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

void init_here_vars(t_here *here)
{
	here->i = 0;
	here->r = 0;
	here->boo = 0;
	here->new = (char *)ft_calloc(sizeof(char), 1);
	here->val = (char *)ft_calloc(sizeof(char), 1);
	here->fd = 0;
	signal(SIGINT, handle_sigint); // no funciona, no sale del heredoc
}

void here_condition(t_here *here)
{
	if (here->boo)
	{
		here->aux = (char *)ft_calloc(sizeof(char), ft_strlen(here->val) + 2);
		bucle_here_aux(here);
		free_and_copy(here);
	}
	else
		here->boo = 1;
}

int	ft_heredoc(char **arr, t_content *cont)
{
	t_here *here;
	
	here = (t_here *)ft_calloc(sizeof(t_here), 1);
	init_here_vars(here);
	while (arr[here->i])
	{
		if (arr[here->i + 1] == NULL)
			here_condition(here);
		free (here->val);
		here->val = readline(">");
		if (!here->val)
		{
			free_no_val(here);
			return (0);
		}
		if (pos_char(here->val, '$'))
		{
			here->aux = ft_add_varent(here->val, pos_char(here->val, '$'), cont[0].global[0].env, cont);
			val_is_aux(here);
		}
		if (!ft_strcmp(arr[here->i], here->val))
			here->i++;
	}
	open_and_write(here);
	return (1);
}
