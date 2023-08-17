#include "minishell.h"

/*
    num = index for the pipes file descriptors
*/

void	ft_executor(t_content *cont)
{
    int i;
    pid_t pid;
    int num_of_commands;
    int num;
    pid_t main_pid;

    i = 0;
    cont[i].signal_sent = 0; // pruebas
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
        printf("parent pid: %d\n", pid);
        cont[i].global->main_getpid = getpid();
        printf("main_getpid: %d\n", cont[i].global->main_getpid);
        main_pid = pid;
        printf("main_pid: %d\n", main_pid);
        // int kill(pid_t pid, int sig);
        //kill(main_pid, SIGINT);
        main_closes_pipes(cont, i, fds, num);
        waitpid(pid, NULL, 0);
        if (cont[i].signal_sent == 1)
        {
            kill(pid, SIGTERM);
        }
        i++;
    }
}
// ************* POR HACER *************

/* se podria mejorar poniendo los perror de los pipe y de los fork
pero entonces me paso de lineas y hay que quitar todas las inicializaciones
del principio y ponerlas en otra funcion */