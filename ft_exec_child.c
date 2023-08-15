#include "minishell.h"

void ft_execute_child(t_content *cont, int i, int (*fds)[2], int num)
{
    if (i == 0) // si es el primer child
    {
        execute_first_child(cont, i, fds, num);
    }
    // si NO es el primer child ni el ultimo
    else if (i > 0 && i < cont[i].global->num_cmd -1)
    {
        execute_middle_children(cont, i, fds, num);
    }
    // si es el ultimo child, que escriba en la salida estandar o en el outfile
    else if (i == cont[i].global->num_cmd - 1)
    {
        execute_last_child(cont, i, fds, num);
    }
    else // quitar esto
    {
        perror("No debe llegar\n");
        exit(-1);
    }
}