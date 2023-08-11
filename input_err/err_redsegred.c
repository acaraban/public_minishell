#include "../minishell.h"

int err_redsegred(char **arr, t_content *cont)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '<' || arr[i][0] == '>' || arr[i][0] == '|')
		{
			if (arr[i + 1] && (arr[i + 1][0] == '<' || arr[i + 1][0] == '>' || arr[i + 1][0] == '|'))
			{
				err_stx("error sintactico\n", cont);
				return (2);
			}
		}
		i++;
	}
	return (0);
}