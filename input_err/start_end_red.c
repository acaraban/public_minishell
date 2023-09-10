#include "../minishell.h"

int	start_end_red(char **vue, t_content *cont)
{
	if (vue[0][0] == '|')
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	return (0);
}
