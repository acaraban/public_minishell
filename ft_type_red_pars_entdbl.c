#include "minishell.h"

void	ft_type_red_entdbl_1(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].infile)
		free (cont[type->h].infile);
	if (!type->ac)
		type->ac = ft_dbl_strdup_str(red->cmd_str[0]);
	else
		type->ac = dobl_prt_free(type->ac, red->cmd_str[0], 0, ft_strlen(red->cmd_str[0]));
	cont[type->h].infile = ft_strdup(".awdrgyj123.txt");
	if (red->cmd_str[1])
		cont[type->h].full_comand = ft_xtr_allsz_free(cont[type->h].full_comand, red->cmd_str, 1);
}

void	ft_type_red_entdbl_2(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].infile)
		free (cont[type->h].infile);
	if (!type->ac)
		type->ac = ft_dbl_strdup_str(red->cmd_str[0]);
	else
		type->ac = dobl_prt_free(type->ac, red->cmd_str[0], 0, ft_strlen(red->cmd_str[0]));
	cont[type->h].infile = ft_strdup(".awdrgyj123.txt");
	if (red->cmd_str[1])
	{
		red->cmd_str = ft_elim_str_free(red->cmd_str, 0);
		cont[type->h].full_comand = ft_dbl_strdup(red->cmd_str);
		cont[type->h].cmd = ft_strdup(red->cmd_str[0]);
	}
	else
	{
		cont[type->h].full_comand = NULL;
		cont[type->h].cmd = NULL;
	}
}

char	**ft_type_red_entdbl(char **final, t_typered *type, t_content *cont)
{
	t_red *red;

	red = (t_red *)malloc(sizeof(t_red) * 1);
	type->i++;
	red->r = 0;
	red->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (red->cmd_str == NULL)
		return (NULL);
	while (red->cmd_str[red->r])
		red->r++;
	if (cont[type->h].cmd)
		ft_type_red_entdbl_1(type, cont, red);
	else
		ft_type_red_entdbl_2(type, cont, red);
	free_dbl(red->cmd_str);
	cont[type->h].nfl = 2;
	free (red);
	return (type->ac);
}
