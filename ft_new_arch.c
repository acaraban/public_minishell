#include "minishell.h"

int new_arch(char *name)
{
    // Nombre del archivo que deseas crear
    const char *nombrearchivo;
	int descriptorarchivo;

	nombrearchivo = ft_strdup(name);
    descriptorarchivo = open(nombrearchivo, O_WRONLY | O_CREAT, 0644);
    if (descriptorarchivo == -1) {
        perror("Error al crear el archivo");
        return 0;
    }
    close(descriptorarchivo);
    return 1;
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
