#include "../minishell.h"

/*
    execve returns -1 in case of an error. And retrieves an specific error
    code stored in the errno variable. Handle every error and print proper
    message.
*/


void handle_execve_error_message(int error_number, t_content *cont, int i)
{
    // 14 -- Bad address PERO yo quiero sacar otro mensaje distinto
    if (error_number == EFAULT) 
    {
        //bash: foo: command not found
        printf("minishell: %s: command not found\n", cont[i].cmd);
    }
    else if (error_number == ENOENT) // 2 ???
    {
        // bash: cd: kfjasldja: No such file or directory
        printf("minishell: %s: ", cont[i].infile);
        printf("%s\n", strerror(error_number));
    }
    else if (error_number == EACCES) // 13 -- Permission denied
    {
        // bash: entrada.md: Permission denied
        printf("minishell: %s: ", cont[i].infile);
        printf("%s\n", strerror(error_number));
    }
    exit (EXIT_FAILURE);
}