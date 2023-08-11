#include "../minishell.h"

void echo(char *txt, int flag)
{
	if (flag == 0)
		ft_printf("%s\n", txt);
	else
		ft_printf("%s", txt);
}