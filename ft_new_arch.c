#include "minishell.h"

/*
    nombrearchivo --> name of the file to create
    If there are not rights to write on the file, this is error msg:
    e.g. bash: <filename>: Permission denied
*/

int	new_arch(char *name)
{
	char	*nombrearchivo;
	int			descriptorarchivo;

	nombrearchivo = ft_strdup(name);
	descriptorarchivo = open(nombrearchivo, O_WRONLY | O_CREAT, 0644);
	if (descriptorarchivo == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(nombrearchivo);
		free (nombrearchivo);
		return (0);
	}
	free (nombrearchivo);
	close(descriptorarchivo);
	return (1);
}

int ft_tam_args(char *txt, t_content *cont)
{
	int i;
	int tam;

	i = 0;
	tam = 1;
	while (txt[i])
	{
		if (txt[i] == '|')
			tam++;
		if (txt[i] == '\"' || txt[i] == '\'')
		{
			if (find_match(txt, i, txt[i]) < 0)
			{
				err_stx("error sintactico\n", cont);
				return (-1);
			}
			i += find_match(txt, i, txt[i]);
		}
		i++;
	}
	return (tam);
}
