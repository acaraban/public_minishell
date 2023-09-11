#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>



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
		here->aux = (char *)calloc(sizeof(char), ft_strlen(here->val) + 2);
		bucle_here_aux(here);
		free_and_copy(here);
	}
	else
		here->boo = 1;
}

void free_no_val(t_here *here)
{
	free(here->val);
	free (here->new);
	ft_printf("exit\n");
}

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
