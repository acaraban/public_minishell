#include "../minishell.h"

int	check_pipe_outredir(char **arr, int i, t_content *cont)
{
	if (!arr[i + 1] || (arr[i + 1][0] == '<' || arr[i + 1][0] == '>' || \
				arr[i + 1][0] == '|' || !arr[i + 1][0]))
	{
		err_stx("error sintactico2\n", cont);
		return (1);
	}
	return (0);
}

int	check_pipe_inredir(char **arr, int i, t_content *cont)
{
	if (!arr[i + 1] || (arr[i + 1][0] == '<' || arr[i + 1][0] == '>' || \
				arr[i + 1][0] == '|' || !arr[i + 1][0]))
	{
		err_stx("error sintactico1\n", cont);
		return (1);
	}
	return (0);
}

/*
	Function to check for syntax errors, in redirs with pipes.
*/

int	err_redsegred(char **arr, t_content *cont)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '>')
		{
			if (check_pipe_inredir(arr, i, cont) == 1)
				return (2);
		}
		if (arr[i][0] == '<')
		{
			if (check_pipe_outredir(arr, i, cont) == 1)
				return (2);
		}
		i++;
	}
	return (0);
}
