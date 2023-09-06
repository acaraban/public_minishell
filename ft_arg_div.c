#include "minishell.h"

void	handle_sigint(int sig)
{
	if (sig == 2)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	ft_arg_div(char *txt, t_global *glb)
{
	char		**final;
	t_content	*cont;
	char		*ot;
	int			tam;
	int			h;
	int			i;
	char		**cmd_str;
	char		**ac;
	//int			cm;

	tam = 1;
	i = 0;
	ot = ft_strdup(txt);
	free(txt);
	txt = ft_strtrim(ot, " ");
	free(ot);
	// while (txt[i])
	// {
	// 	if (txt[i] == '|')
	// 		tam++;
	// 	i++;
	// }
	// if (ft_strlen(txt) == 0)
	// 	tam = 0;
	// tam2 = tam;
	// i = 0;
	cont = (t_content *)calloc(sizeof(t_content), tam + 1);
	if (ft_tam_args(txt, cont) < 0)
		return ;
	glb->num_cmd = ft_tam_args(txt, cont);
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
	final = ft_specials(txt, cont, 1);
	if (final == NULL)
		return ;
	tam = 0;
	while (final[tam])
		tam++;
	i = 0;
	h = 0;
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
					return ;
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
	//ft_printf("este es h: %d\n", h);
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
