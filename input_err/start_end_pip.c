#include "../minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

char	**start_end_pip(char **vue, t_content *cont)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (vue[i])
		i++;
	if (vue[i - 1][0] == '|')
	{
		err_stx("error sintactico\n", cont);
		return (NULL);
	}
	return (vue);
}
