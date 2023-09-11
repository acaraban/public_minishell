#include "minishell.h"

int	ft_type_red_entsim(char **final, t_typered *type, t_content *cont)
{
	int r;
	char **cmd_str;
	int fd;

	type->i++;
	r = 0;
	fd = 0;
	cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (cmd_str == NULL)
		return (-1);
	while (cmd_str[r])
		r++;
	if (cont[type->h].cmd)
	{
		if (cont[type->h].infile)
			free (cont[type->h].infile);
		if (cmd_str[r - 1])
			cont[type->h].infile = ft_strdup(cmd_str[r - 1]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
	}
	else
	{
		if (cont[type->h].infile)
			free (cont[type->h].infile);
		if (cmd_str[0])
			cont[type->h].infile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (cmd_str[1])
		{
			cmd_str = ft_elim_str_free(cmd_str, 0);
			cont[type->h].full_comand = ft_dbl_strdup(cmd_str);
			cont[type->h].cmd = ft_strdup(cmd_str[0]);
		}
		else
		{
			fd = open(cont[type->h].infile, O_RDONLY); 
			if (fd == -1)
			{
				ft_printf("bash: %s: No such file or directory\n", cont[type->h].infile);
				cont->global->err_stat = 1;
			}
			else
				close (fd);
		}
	}
	free_dbl(cmd_str);
	cont[type->h].nfl = 1;
	return (type->i);
}

int	ft_type_red_salsim(char **final, t_typered *type, t_content *cont)
{
	int r;
	char **cmd_str;

	type->i++;
	r = 0;
	cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (cmd_str == NULL)
		return (-1);
	while (cmd_str[r])
		r++;
	if (cont[type->h].cmd)
	{
		if (cont[type->h].outfile)
			free (cont[type->h].outfile);
		if (cmd_str[0])
			cont[type->h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		if (cmd_str[1])
			cont[type->h].full_comand = ft_xtr_allsz_free(cont[type->h].full_comand, cmd_str, 1);
	}
	else
	{
		if (cont[type->h].outfile)
			free (cont[type->h].outfile);
		if (cmd_str[0])
			cont[type->h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		cmd_str = ft_elim_str_free(cmd_str, 0);
		if (cmd_str[0] && cmd_str[1])
		{
			cont[type->h].full_comand = ft_dbl_strdup(cmd_str);
			cont[type->h].cmd = ft_strdup(cmd_str[0]);
		}
	}
	free_dbl(cmd_str);
	cont[type->h].tfl = 1;
	return (type->i);
}

int	ft_type_red_saldbl(char **final, t_typered *type, t_content *cont)
{
	int r;
	char **cmd_str;

	type->i++;
	r = 0;
	cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (cmd_str == NULL)
		return (-1);
	while (cmd_str[r])
		r++;
	if (cont[type->h].cmd)
	{
		if (cont[type->h].outfile)
			free (cont[type->h].outfile);
		if (cmd_str[0])
			cont[type->h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		if (cmd_str[1])
			cont[type->h].full_comand = ft_xtr_allsz_free(cont[type->h].full_comand, cmd_str, 1);
	}
	else
	{
		if (cont[type->h].outfile)
			free (cont[type->h].outfile);
		if (cmd_str[0])
			cont[type->h].outfile = ft_strdup(cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		if (cmd_str[1])
		{
			cmd_str = ft_elim_str_free(cmd_str, 0);
			cont[type->h].full_comand = ft_dbl_strdup(cmd_str);
			cont[type->h].cmd = ft_strdup(cmd_str[0]);
		}
	}
	free_dbl(cmd_str);
	cont[type->h].tfl = 2;
	return (type->i);
}

char	**ft_type_red_entdbl(char **final, t_typered *type, t_content *cont)
{
	int r;
	char **cmd_str;

	type->i++;
	r = 0;
	cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (cmd_str == NULL)
		return (NULL);
	while (cmd_str[r])
		r++;
	if (cont[type->h].cmd)
	{
		if (cont[type->h].infile)
			free (cont[type->h].infile);
		if (!type->ac)
			type->ac = ft_dbl_strdup_str(cmd_str[0]);
		else
			type->ac = dobl_prt_free(type->ac, cmd_str[0], 0, ft_strlen(cmd_str[0]));
		cont[type->h].infile = ft_strdup(".awdrgyj123.txt");
		if (cmd_str[1])
			cont[type->h].full_comand = ft_xtr_allsz_free(cont[type->h].full_comand, cmd_str, 1);
	}
	else
	{
		if (cont[type->h].infile)
			free (cont[type->h].infile);
		if (!type->ac)
			type->ac = ft_dbl_strdup_str(cmd_str[0]);
		else
			type->ac = dobl_prt_free(type->ac, cmd_str[0], 0, ft_strlen(cmd_str[0]));
		cont[type->h].infile = ft_strdup(".awdrgyj123.txt");
		if (cmd_str[1])
		{
			cmd_str = ft_elim_str_free(cmd_str, 0);
			cont[type->h].full_comand = ft_dbl_strdup(cmd_str);
			cont[type->h].cmd = ft_strdup(cmd_str[0]);
		}
		else
		{
			cont[type->h].full_comand = NULL;
			cont[type->h].cmd = NULL;
		}
	}
	free_dbl(cmd_str);
	cont[type->h].nfl = 2;
	return (type->ac);
}
