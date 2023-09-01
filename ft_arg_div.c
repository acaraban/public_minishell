#include "minishell.h"

void ft_arg_div(char *txt, t_global *glb)
{
	char **final;
	t_content *cont;
	char *ot;
	int tam;
	int tam2;
	int h;
	int i;

	tam = 1;
	i = 0;
	ot = ft_strdup(txt);
	free(txt);
	txt = ft_strtrim(ot, " ");
	free (ot);
	while (txt[i])
	{
		if (txt[i] == '|')
			tam++;
		i++;
	}
	if (ft_strlen(txt) == 0)
		tam = 0;
	glb->num_cmd = tam;
	tam2 = tam;
	i = 0;
	cont = (t_content *)calloc(sizeof(t_content), tam + 1);
	tam = 0;
	while (tam < tam2)
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
	final = ft_specials(txt, cont, 1);
	if (final == NULL)
		return;




	tam = 0;
	while (final[tam])
		tam++;
	char **cmd_str;
	i = 0;
	h = 0;
	char **ac;

	ac = NULL;
	while (final[i])
	{
		if (final[i][0] != '<' && final[i][0] != '>' && final[i][0] != '|')
		{
			cmd_str = ft_shell_split(final[i], ' ', cont);
			if (cmd_str == NULL)
				return ;
			cont[h].cmd = ft_strdup(cmd_str[0]);
			cont[h].full_comand = ft_dbl_strdup(cmd_str);
			free_dbl (cmd_str);
		}
		else if (final[i][0] == '|')
			h++;
		else
		{
			if (final[i][0] == '<' && final[i][1] == '<')
			{
				ac = ft_type_red_entdbl(final, ac, i, h, cont);
				if (ac == NULL)
					return ;
				ft_printf("esto es ac[0]\n", ac[0]);
				i++;
			}
			else if (final[i][0] == '<')
			{
				i = ft_type_red_entsim(final, i, h, cont);
				if (i < 0)
					return ;
			}
				
			else if (final[i][0] == '>' && final[i][1] == '>')
			{
				i = ft_type_red_saldbl(final, i, h, cont);
				if (i < 0)
					return ;
			}
			else if (final[i][0] == '>')
			{
				i = ft_type_red_salsim(final, i, h, cont);
				if (i < 0)
					return ;
			}
		}
		i++;
	}
	if (ac)
	{
		ft_heredoc(ac);
		free_dbl(ac);
	}

	ft_executor(cont);


	////////////imprimir el struct //////////////////////
	/*int l;

	l = 0;
	while (l < tam2)
	{
		ft_printf("este es el comando: %s", cont[l].cmd);
		ft_printf("\neste es el comando completo:\n");
		int cm = 0;
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
	}*/
	// recorrer variables de entorno de la minishell, no del mac, y eliminar OLDPWD
	ft_delete_env_oldpwd(cont);
	//
	ft_executor(cont);

	//////////////parte del codigo////////////////*/
	
}
