#include "../minishell.h"

void	err_stx(char *txt, t_content *cont)
{
	ft_printf("%s", txt);
	cont->global->err_stat = STX_ERR;
}
