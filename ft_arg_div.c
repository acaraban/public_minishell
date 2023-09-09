#include "minishell.h"

void init_cont_vars(t_global *glb, t_content *cont)
{
	int			tam;
	
	tam = 0;
	while (tam < glb->num_cmd)
	{
		cont[tam].global = glb;
		cont[tam].nfl = 0;
		cont[tam].tfl = 0;
		cont[tam].infile = NULL;
		cont[tam].outfile = NULL;
		cont[tam].full_comand = NULL;
		cont[tam].cmd = NULL;
		tam++;
	}
}

char *init_argdiv_vars(char *txt)
{
	int			i;
	char		*ot;

	i = 0;
	ot = ft_strdup(txt);
	free(txt);
	txt = ft_strtrim(ot, " ");
	free(ot);
	return (txt);
}

char **arg_parsing(char **final, t_content *cont)
{
	int			i;
	int			h;
	char		**cmd_str;
	char		**ac;
	
	i = 0;
	h = 0;
	ac = NULL;
	while (final[i])
	{
		if (final[i][0] != '<' && final[i][0] != '>' && final[i][0] != '|')
		{
			cmd_str = ft_shell_split(final[i], ' ', cont);
			if (cmd_str == NULL)
				return (NULL);
			cont[h].cmd = ft_strdup(cmd_str[0]);
			cont[h].full_comand = ft_dbl_strdup(cmd_str);
			free_dbl(cmd_str);
		}
		else if (final[i][0] == '|')
			h++;
		else
		{
			if (final[i][0] == '<' && final[i][1] == '<')
			{
				ac = ft_type_red_entdbl(final, ac, i, h, cont);
				if (ac == NULL)
					return (NULL);
				i++;
			}
			else if (final[i][0] == '<')
			{
				i = ft_type_red_entsim(final, i, h, cont);
				if (i < 0)
					return (NULL);
			}
			else if (final[i][0] == '>' && final[i][1] == '>')
			{
				i = ft_type_red_saldbl(final, i, h, cont);
				if (i < 0)
					return (NULL);
			}
			else if (final[i][0] == '>')
			{
				i = ft_type_red_salsim(final, i, h, cont);
				if (i < 0)
					return (NULL);
			}
		}
		i++;
	}
	return (ac);
}

void	ft_arg_div(char *txt, t_global *glb)
{
	char		**final;
	t_content	*cont;
	int			tam;
	char		**ac;

	tam = 1;
	txt = init_argdiv_vars(txt);
	cont = (t_content *)calloc(sizeof(t_content), tam + 1);
	if (ft_tam_args(txt, cont) < 0)
		return ;
	glb->num_cmd = ft_tam_args(txt, cont);
	free (cont);
	cont = (t_content *)calloc(sizeof(t_content), glb->num_cmd + 1);
	init_cont_vars(glb, cont);
	final = ft_specials(txt, cont, 1);
	if (final == NULL)
		return ;
	ac = arg_parsing(final, cont);
	if (ac)
	{
		if (!ft_heredoc(ac))
			return ;
		free_dbl(ac);
	}
	ft_executor(cont);
	/*/ft_printf("pasa executor?\n");
	//////////////imprimir el struct //////////////////////
	int l;
	l = 0;
	int cm = 0;
	while (l < glb->num_cmd)
	{
		ft_printf("este es el comando: %s", cont[l].cmd);
		ft_printf("\neste es el comando completo:\n");
		cm = 0;
		while (cont[l].full_comand[cm])
		{
			ft_printf("%s\n", cont[l].full_comand[cm]);
			cm++;
		}
		ft_printf("infile: %d ", cont[l].nfl);
		if (cont[l].nfl)
			ft_printf("%s", cont[l].infile);
		ft_printf("\n");
		ft_printf("outfile: %d ", cont[l].tfl);
		if (cont[l].tfl)
			ft_printf("%s\n", cont[l].outfile);
		ft_printf("\n\n-------------------------------\n");
		l++;
	}
	//////////////parte del codigo////////////////*/
}
