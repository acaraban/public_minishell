#include "../minishell.h"

void err_cmd(char *txt, t_content *cont)
{
	ft_printf("%s", txt);
	cont->global->err_stat = 1;
}