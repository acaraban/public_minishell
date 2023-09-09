#include "minishell.h"

int	ft_type_red_entsim(char **final, int i, int h, t_content *cont)
{
	int r;
	char **cmd_str;
	int fd;

	i++;
	r = 0;
	fd = 0;
	cmd_str = ft_shell_split(final[i], ' ', cont);
	if (cmd_str == NULL)
		return (-1);
	while (cmd_str[r])
		r++;
	if (cont[h].cmd)
	{
		if (cont[h].infile)
			free (cont[h].infile);
		if (cmd_str[r - 1])
			cont[h].infile = ft_strdup(cmd_str[r - 1]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
	}
	else
	{
		if (cont[h].infile)
			free (cont[h].infile);
		if (cmd_str[0])
			cont[h].infile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (cmd_str[1])
		{
			cmd_str = ft_elim_str_free(cmd_str, 0);
			cont[h].full_comand = ft_dbl_strdup(cmd_str);
			cont[h].cmd = ft_strdup(cmd_str[0]);
		}
		else
		{
			fd = open(cont[h].infile, O_RDONLY); 
			if (fd == -1)
			{
				ft_printf("bash: %s: No such file or directory\n", cont[h].infile);
				cont->global->err_stat = 1;
			}
			else
				close (fd);
		}
	}
	free_dbl(cmd_str);
	cont[h].nfl = 1;
	return (i);
}

int	ft_type_red_salsim(char **final, int i, int h, t_content *cont)
{
	int r;
	char **cmd_str;

	i++;
	r = 0;
	cmd_str = ft_shell_split(final[i], ' ', cont);
	if (cmd_str == NULL)
		return (-1);
	while (cmd_str[r])
		r++;
	if (cont[h].cmd)
	{
		if (cont[h].outfile)
			free (cont[h].outfile);
		if (cmd_str[0])
			cont[h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[h].outfile))
			return (-1);
		if (cmd_str[1])
			cont[h].full_comand = ft_xtr_allsz_free(cont[h].full_comand, cmd_str, 1);
	}
	else
	{
		if (cont[h].outfile)
			free (cont[h].outfile);
		if (cmd_str[0])
			cont[h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[h].outfile))
			return (-1);
		cmd_str = ft_elim_str_free(cmd_str, 0);
		if (cmd_str[0] && cmd_str[1])
		{
			cont[h].full_comand = ft_dbl_strdup(cmd_str);
			cont[h].cmd = ft_strdup(cmd_str[0]);
		}
	}
	free_dbl(cmd_str);
	cont[h].tfl = 1;
	return (i);
}

int	ft_type_red_saldbl(char **final, int i, int h, t_content *cont)
{
	int r;
	char **cmd_str;

	i++;
	r = 0;
	cmd_str = ft_shell_split(final[i], ' ', cont);
	if (cmd_str == NULL)
		return (-1);
	while (cmd_str[r])
		r++;
	if (cont[h].cmd)
	{
		if (cont[h].outfile)
			free (cont[h].outfile);
		if (cmd_str[0])
			cont[h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[h].outfile))
			return (-1);
		if (cmd_str[1])
			cont[h].full_comand = ft_xtr_allsz_free(cont[h].full_comand, cmd_str, 1);
	}
	else
	{
		if (cont[h].outfile)
			free (cont[h].outfile);
		if (cmd_str[0])
			cont[h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[h].outfile))
			return (-1);
		if (cmd_str[1])
		{
			cmd_str = ft_elim_str_free(cmd_str, 0);
			cont[h].full_comand = ft_dbl_strdup(cmd_str);
			cont[h].cmd = ft_strdup(cmd_str[0]);
		}
	}
	free_dbl(cmd_str);
	cont[h].tfl = 2;
	return (i);
}

char	**ft_type_red_entdbl(char **final, char **ac, int i, int h, t_content *cont)
{
	int r;
	char **cmd_str;

	i++;
	r = 0;
	cmd_str = ft_shell_split(final[i], ' ', cont);
	if (cmd_str == NULL)
		return (NULL);
	while (cmd_str[r])
		r++;
	if (cont[h].cmd)
	{
		if (cont[h].infile)
			free (cont[h].infile);
		if (!ac)
			ac = ft_dbl_strdup_str(cmd_str[0]);
		else
			ac = dobl_prt_free(ac, cmd_str[0], 0, ft_strlen(cmd_str[0]));
		//ft_dbl_printf("este es ac", ac, "\n", 0);
		cont[h].infile = ft_strdup(".awdrgyj123.txt");
		if (cmd_str[1])
			cont[h].full_comand = ft_xtr_allsz_free(cont[h].full_comand, cmd_str, 1);
	}
	else
	{
		if (cont[h].infile)
			free (cont[h].infile);
		if (!ac)
			ac = ft_dbl_strdup_str(cmd_str[0]);
		else
			ac = dobl_prt_free(ac, cmd_str[0], 0, ft_strlen(cmd_str[0]));
		cont[h].infile = ft_strdup(".awdrgyj123.txt");
		if (cmd_str[1])
		{
			cmd_str = ft_elim_str_free(cmd_str, 0);
			cont[h].full_comand = ft_dbl_strdup(cmd_str);
			cont[h].cmd = ft_strdup(cmd_str[0]);
		}
		else
		{
			cont[h].full_comand = NULL;
			cont[h].cmd = NULL;
		}
	}
	free_dbl(cmd_str);
	cont[h].nfl = 2;
	return (ac);
}
