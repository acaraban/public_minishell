#include "../minishell.h"

int	err_nolstpar(char *txt, int pos, t_content *cont)
{
	int	i;

	i = 0;
	while (txt[i + pos] != ')' && txt[i + pos])
		i++;
	if (txt[i + pos] != ')')
	{
		err_stx("error sintactico\n", cont);
		return (0);
	}
	return (i);
}
