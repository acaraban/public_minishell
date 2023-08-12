#include "minishell.h"


void ft_arg_div(char *txt, t_global *glb)
{
	char **final;
	char ***cmd_str;
	t_content *cont;
	int tam;
	int tam2;
	int h;
	int i;

	tam = 1;
	i = 0;
	while (txt[i])
	{
		if (txt[i] == '|')
			tam++;
		i++;
	}
	tam2 = tam;
	i = 0;
	cont = (t_content *)calloc(sizeof(t_content), tam + 1);
	tam = 0;
	while (tam < tam2)
	{
		cont[tam].global = glb;
		cont[tam].nfl = 0;
		cont[tam].tfl = 0;
		tam++;
	}
	final = ft_specials(txt, cont, 1);
	if (final == NULL)
		return;




	tam = 0;
	while (final[tam])
		tam++;
	cmd_str = (char ***)calloc(sizeof(char **), tam + 1);
	cmd_str[tam] = NULL;
	i = 0;
	h = 0;
	int r = 0;
	while (final[i])
	{
		if (final[i][0] != '<' && final[i][0] != '>' && final[i][0] != '|')
		{
			cmd_str[i] = ft_com_split(final[i], ' ', cont);
			cont[h].cmd = cmd_str[i][0];
			cont[h].full_comand = cmd_str[i];
		}
		else if (final[i][0] == '|')
			h++;
		else
		{
			cmd_str[i] = &final[i];
			if (final[i][0] == '<' && final[i][1] == '<')
			{
				i++;
				cmd_str[i] = ft_com_split(final[i], ' ', cont);
				cont[h].infile = cmd_str[i][0];
				cont[h].nfl = 2;
				if (cmd_str[i][1])
					cont[h].full_comand = ft_xtr_allsz(cont[h].full_comand, cmd_str[i], 1);
			}
			else if (final[i][0] == '<')
			{
				i++;
				cmd_str[i] = ft_com_split(final[i], ' ', cont);
				while (cmd_str[i][r])
					r++;
				cont[h].infile = cmd_str[i][r - 1];
				cont[h].nfl = 1;
				r = 0;
			}
			else if (final[i][0] == '>' && final[i][1] == '>')
			{
				i++;
				cmd_str[i] = ft_com_split(final[i], ' ', cont);
				cont[h].outfile = cmd_str[i][0];
				cont[h].tfl = 2;
				if (cmd_str[i][1])
					cont[h].full_comand = ft_xtr_allsz(cont[h].full_comand, cmd_str[i], 1);
			}
			else if (final[i][0] == '>')
			{
				i++;
				cmd_str[i] = ft_com_split(final[i], ' ', cont);
				cont[h].outfile = cmd_str[i][0];
				cont[h].tfl = 1;
				if (cmd_str[i][1])
					cont[h].full_comand = ft_xtr_allsz(cont[h].full_comand, cmd_str[i], 1);
			}
				
		}
		i++;
	}

	// aqui ??
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

	//////////////parte del codigo////////////////
	cont[0].global[0].new_stat = cont[0].global[0].err_stat;
	cont[0].global[0].err_stat = 0;
}
