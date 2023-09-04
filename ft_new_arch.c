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
