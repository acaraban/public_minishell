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
            ft_execute_child(cont, i, fds, num);
        main_closes_pipes(cont, i, fds, num);
        waitpid(pid, NULL, 0);
        i++;
    }
}
