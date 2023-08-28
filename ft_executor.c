#include "minishell.h"

/*void start_pipe_and_fork(t_content *cont, int i, int (*fds)[2], int num)
{
    if (pipe(fds[i]) == -1)
    {
        perror("Error in pipe\n");
        return ;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("Error in fork\n");
        return ;
    }
    if (pid == 0)
        ft_execute_child(cont, i, fds, num);
}*/

/*int start_fork(pid_t pid)
{
    pid = fork();
    if (pid == -1)
    {
        perror("Error in fork\n");
        return (1);
    }
    if (pid == 0)
        return (0);
    return (0);
}*/

void init_builtins(t_content *cont, int i)
{
    cont[i].builtin = 0;
    cont[i].which_builtin = 0;
}


/*
    num = index for the pipes' file descriptors.
    1st -- Check if command is a built-in without redirs. Execute in parent.
    2nd -- Fork process for every command found. Execute command in the child
    process with a custom built-in function or with the execve.
*/

// ejecutar los builtins que si permiten redir (pwd, ..) after fork
// y tener en cuenta los dups

void	ft_executor(t_content *cont)
{
    int i;
    pid_t pid;

    i = 0;
    int fds[cont->global->num_cmd][2];
    cont->global->environ_path = ft_env_path(cont->global->env);
    while (i < cont->global->num_cmd)
    {
        if (is_builtin_noredir(cont, i) == 0)
            return ;
        init_builtins(cont, i);
        if (pipe(fds[i]) == -1)
            return ;
        pid = fork();
        if (pid == -1)
            return ;
        if (pid == 0)
            ft_execute_child(cont, i, fds, i);
        main_closes_pipes(cont, i, fds, i);
        waitpid(pid, NULL, 0);
        i++;
    }
}
// ************* POR HACER *************

/* se podria mejorar poniendo los perror de los pipe y de los fork
pero entonces me paso de lineas 
num of commands y num tienen valores repetidos, como reducir lineas?
*/