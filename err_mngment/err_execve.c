#include "../minishell.h"

/*
    execve returns -1 in case of an error. And retrieves an specific error
    code stored in the errno variable. Handle every error and print proper
    message.
    The messages should be printed in the error output, and not stdout
    otherwise gets redirected with dup2 to the pipe and nothing is printed
    in the console.
    errno 14 -- Bad address, instead should print bash: foo: command not found
    errno 2 ENOENT -- bash: cd: kfjasldja: No such file or directory
                      e.g. wc -l < input.txt
    errno 13 EACCES -- Permission denied
                       e.g. bash: entrada.md: Permission denied
                            bash: cd: carpeta/: Permission denied
*/

void handle_execve_error_message(t_content *cont, int i)
{
    if (errno == EFAULT) 
    {
        ft_putstr_fd("minishelli: ", 2);
        ft_putstr_fd(ft_strjoin(cont[i].cmd, ": command not found\n"), 2);
        // update exit status after executing command
        cont->global->err_stat = 127; // esto no actualiza nada
        // hay que hacer este cambio en el padre (main)
    }
    else if (errno == ENOENT) // 2
    {
        ft_putstr_fd("minishell: ", 2);
        perror(cont[i].infile);
    }
    else if (errno == EACCES) 
    {
        ft_putstr_fd("minishell: ", 2);
        if (cont[i].infile)
        {
            perror(cont[i].infile);
        }
        else
        {
            perror(cont[i].cmd);
        }
    }
}