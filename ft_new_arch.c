#include "minishell.h"

/*
    nombrearchivo --> name of the file to create
    If there are not rights to write on the file, this is error msg:
    e.g. bash: <filename>: Permission denied
*/

int	new_arch(char *name)
{
	const char	*nombrearchivo;
	int			descriptorarchivo;

	nombrearchivo = ft_strdup(name);
	descriptorarchivo = open(nombrearchivo, O_WRONLY | O_CREAT, 0644);
	if (descriptorarchivo == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(nombrearchivo);
		return (0);
	}
	close(descriptorarchivo);
	return (1);
}
