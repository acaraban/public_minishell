#include "../minishell.h"

/*
    execve returns -1 in case of an error. And retrieves an specific error
    code stored in the errno variable. Handle every error and print proper
    message.
*/


void handle_execve_error_message(int error_number, t_content *cont, int i)
{
    if (error_number == EFAULT) // 14 -- Bad address
    {
        //ft_putstr_fd("este sería tipo de errror 14 EFAULT\n", 2);
        //perror("Errrrror");
        //printf("%s\n", strerror(error_number));
        printf("minishell: %s: command not found\n", cont[i].cmd);
        //bash: foo: command not found
    }
    //else if (error_number == )
}