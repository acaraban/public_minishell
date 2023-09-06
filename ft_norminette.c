#include "minishell.h"

void ft_nrmntt_1(t_global *glb)
{
	glb[0].new_stat = glb[0].err_stat;
	glb[0].err_stat = 0;
}

void ft_free_cont(t_content *cont)
{
	int i;

	i = 0;
	while (i < cont->global->num_cmd)
	{
		free(cont[i].access_path);
		free(cont[i].cmd);
		free_dbl(cont[i].full_comand);
		free(cont[i].infile);
		free(cont[i].outfile);
		i++;
	}
	free(cont);
}
