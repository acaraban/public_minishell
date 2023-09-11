#include "minishell.h"

typedef struct s_red
{
	int r;
	char **cmd_str;
}t_red;

int	ft_type_red_entsim_1(t_typered *type, t_content *cont, t_red *red)
{
	if (red->cmd_str == NULL)
		return (-1);
	while (red->cmd_str[red->r])
		red->r++;
	if (cont[type->h].cmd)
	{
		if (cont[type->h].infile)
			free (cont[type->h].infile);
		if (red->cmd_str[red->r - 1])
			cont[type->h].infile = ft_strdup(red->cmd_str[red->r - 1]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		return (1);
	}
	return (0);
}

int	ft_type_red_entsim_2(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].infile)
		free (cont[type->h].infile);
	if (red->cmd_str[0])
		cont[type->h].infile = ft_strdup(red->cmd_str[0]);
	else
	{
		err_stx("error sintactico\n", cont);
		return (-1);
	}
	if (red->cmd_str[1])
	{
		red->cmd_str = ft_elim_str_free(red->cmd_str, 0);
		cont[type->h].full_comand = ft_dbl_strdup(red->cmd_str);
		cont[type->h].cmd = ft_strdup(red->cmd_str[0]);
		return (1);
	}
	return (0);
}

int	ft_type_red_entsim_3(t_typered *type, t_content *cont)
{
	int fd;

	fd = open(cont[type->h].infile, O_RDONLY); 
	if (fd == -1)
	{
		ft_printf("bash: %s: No such file or directory\n", cont[type->h].infile);
		cont->global->err_stat = 1;
	}
	else
		close (fd);
	return (0);
}

int	ft_type_red_entsim(char **final, t_typered *type, t_content *cont)
{
	t_red *red;
	int res;

	red = (t_red *)malloc(sizeof(t_red) * 1);
	type->i++;
	red->r = 0;
	red->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	res = ft_type_red_entsim_1(type, cont, red);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		res = ft_type_red_entsim_2(type, cont, red);
		if (res == -1)
			return (-1);
		if (res == 0)
			ft_type_red_entsim_3(type, cont);
	}
	free_dbl(red->cmd_str);
	cont[type->h].nfl = 1;
	free (red);
	return (type->i);
}

int	ft_type_red_salsim_1(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].cmd)
	{
		if (cont[type->h].outfile)
			free (cont[type->h].outfile);
		if (red->cmd_str[0])
			cont[type->h].outfile = ft_strdup(red->cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		if (red->cmd_str[1])
			cont[type->h].full_comand = ft_xtr_allsz_free(cont[type->h].full_comand, red->cmd_str, 1);
		return (1);
	}
	return (0);
}

int	ft_type_red_salsim_2(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].outfile)
		free (cont[type->h].outfile);
	if (red->cmd_str[0])
		cont[type->h].outfile = ft_strdup(red->cmd_str[0]);
	else
	{
		err_stx("error sintactico\n", cont);
		return (-1);
	}
	if (!new_arch(cont[type->h].outfile))
		return (-1);
	red->cmd_str = ft_elim_str_free(red->cmd_str, 0);
	if (red->cmd_str[0] && red->cmd_str[1])
	{
		cont[type->h].full_comand = ft_dbl_strdup(red->cmd_str);
		cont[type->h].cmd = ft_strdup(red->cmd_str[0]);
	}
	return (0);
}

int	ft_type_red_salsim(char **final, t_typered *type, t_content *cont)
{
	t_red *red;
	int res;

	red = (t_red *)malloc(sizeof(t_red) * 1);
	type->i++;
	red->r = 0;
	red->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (red->cmd_str == NULL)
		return (-1);
	while (red->cmd_str[red->r])
		red->r++;
	res = ft_type_red_salsim_1(type, cont, red);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		res = ft_type_red_salsim_2(type, cont, red);
		if (res == -1)
			return (-1);
	}
	free_dbl(red->cmd_str);
	cont[type->h].tfl = 1;
	free (red);
	return (type->i);
}

int	ft_type_red_saldbl_1(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].cmd)
	{
		if (cont[type->h].outfile)
			free (cont[type->h].outfile);
		if (red->cmd_str[0])
			cont[type->h].outfile = ft_strdup(red->cmd_str[0]);
		else
		{
			err_stx("error sintactico\n", cont);
			return (-1);
		}
		if (!new_arch(cont[type->h].outfile))
			return (-1);
		if (red->cmd_str[1])
		{
			cont[type->h].full_comand = ft_xtr_allsz_free(cont[type->h].full_comand, red->cmd_str, 1);
		}
			
		return (1);
	}
	return (0);
}

int	ft_type_red_saldbl_2(t_typered *type, t_content *cont, t_red *red)
{
	if (cont[type->h].outfile)
		free (cont[type->h].outfile);
	if (red->cmd_str[0])
		cont[type->h].outfile = ft_strdup(red->cmd_str[0]);
	else
	{
		err_stx("error sintactico\n", cont);
		return (-1);
	}
	if (!new_arch(cont[type->h].outfile))
		return (-1);
	red->cmd_str = ft_elim_str_free(red->cmd_str, 0);
	if (red->cmd_str[0] && red->cmd_str[1])
	{
		cont[type->h].full_comand = ft_dbl_strdup(red->cmd_str);
		cont[type->h].cmd = ft_strdup(red->cmd_str[0]);
	}
	return (0);
}

int	ft_type_red_saldbl(char **final, t_typered *type, t_content *cont)
{
	t_red *red;
	int res;

	red = (t_red *)malloc(sizeof(t_red) * 1);
	type->i++;
	red->r = 0;
	red->cmd_str = ft_shell_split(final[type->i], ' ', cont);
	if (red->cmd_str == NULL)
		return (-1);
	while (red->cmd_str[red->r])
		red->r++;
	res = ft_type_red_salsim_1(type, cont, red);
	if (res == -1)
		return (-1);
	if (res == 0)
	{
		res = ft_type_red_salsim_2(type, cont, red);
		if (res == -1)
			return (-1);
	}
	free_dbl(red->cmd_str);
	cont[type->h].tfl = 2;
	free (red);
	return (type->i);
}

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
