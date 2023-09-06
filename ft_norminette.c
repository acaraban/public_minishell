#include "minishell.h"

void ft_nrmntt_1(t_global *glb, char *txt)
{
	free(txt);
	glb[0].new_stat = glb[0].err_stat;
	glb[0].err_stat = 0;
}
