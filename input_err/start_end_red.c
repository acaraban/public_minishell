#include "../minishell.h"

int start_end_red(char **vue, t_content *cont)
{
	int i;

	i = 0;
	if (vue[0][0] == '<' || vue[0][0] == '|')
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	while (vue[i])
		i++;
	if (vue[i - 1][0] == '<' || vue[i - 1][0] == '>')
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	return (0);
}