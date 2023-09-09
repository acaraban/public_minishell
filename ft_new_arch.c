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

int ft_tam_args(char *txt, t_global *glb)
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
				ft_printf("error sintactico\n");
				glb->err_stat = STX_ERR;
				return (-1);
			}
			i += find_match(txt, i, txt[i]);
		}
		i++;
	}
	return (tam);
}

char **convert_str_trim(char **vue)
{
	int i;
	char *aux;
	
	i = 0;
	while (vue[i])
	{
		aux = ft_strdup(vue[i]);
		free (vue[i]);
		vue[i] = ft_strtrim(aux, " ");
		free (aux);
		i++;
	}
	return (vue);
}
