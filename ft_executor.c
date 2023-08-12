#include "minishell.h"

void	ft_executor(t_content *cont)
{
    int i;
    printf("empiezo\n");
    printf("numero de comandos\n"); // falta que me pase el numero de comandos
    int num_of_commands; // tmp

    i = 0;
    num_of_commands = 3; // tmp
    while (i < num_of_commands)
    {
        printf("cmd %s\n", cont[i].cmd);
        cont[i].environ_path = ft_env_path(cont[i].global->env);
        printf("environ path %s\n", cont[i].environ_path);
        cont[i].access_path = ft_access_program(cont[i].environ_path, cont[i].cmd);
        printf("access path %s\n", cont[i].access_path);
        i++;
    }
}