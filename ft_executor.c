#include "minishell.h"

/*
    num = index for the pipes file descriptors
*/

void	ft_executor(t_content *cont)
{
    int i;
    pid_t pid;
    int num_of_commands; // tmp
    int num;

    i = 0;
    num_of_commands = cont[i].global->num_cmd;
    int fds[num_of_commands][2];
    cont->global->environ_path = ft_env_path(cont->global->env);
    while (i < num_of_commands)
    {
        cont[i].builtin = 0;
        cont[i].which_builtin = 0;
        num = i;
        if (pipe(fds[i]) == -1)
            return ;
        pid = fork();
        if (pid == -1)
            return ;
        if (pid == 0)
        {
            if (i == 0) // si es el primer child
            {
                execute_first_child(cont, i, fds, num);
            }
            // si NO es el primer child ni el ultimo
            else if (i > 0 && i < num_of_commands -1)
            {
                execute_middle_children(cont, i, fds, num);
            }
            // si es el ultimo child, que escriba en la salida estandar o en el outfile
            else if (i == num_of_commands - 1)
            {
                execute_last_child(cont, i, fds, num);
            }
        }
        main_closes_pipes(cont, i, fds, num);
        // waitpid
        waitpid(pid, NULL, 0);
        i++;
    }
}
