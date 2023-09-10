#include "../minishell.h"

int	err_dobpip(char *txt, int i, t_content *cont)
{
	if (txt[i] == '|' && txt[i + 1] == '|')
	{
		err_stx("error sintactico\n", cont);
		return (2);
	}
	return (0);
}
