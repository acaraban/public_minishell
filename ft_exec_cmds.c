#include "minishell.h"


/* Function to check if the command is a built-in. */

int is_builtin(t_content *cont, int i)
{
    if ((ft_strcmp(cont[i].full_comand[0], "echo") == 0) && (strcmp(cont[i].full_comand[1], "-n") == 0))
    {
        printf("dentro de echo, son iguales y el segundo arg es -n\n");
        cont[i].which_builtin = 1;
        return (0);
    }
    else if (ft_strcmp(cont[i].cmd, "cd") == 0)
    {
        printf("yes, soy built in: %s\n", cont[i].cmd);
        cont[i].which_builtin = 2;
        return (0);
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "pwd") == 0) && (cont[i].full_comand[1] == NULL))
    {
        printf("dentro de pwd, no tiene flags\n");
        cont[i].which_builtin = 3;
        return(0);
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "export") == 0))
    {
        cont[i].which_builtin = 4;
        return(0);
    }
    return (1);
}

/* Function to execute the appropiate custom built-in command. */

void exec_builtin(t_content *cont, int i)
{
    if (cont[i].which_builtin == 1)
    {
        custom_echo(cont, i);
    }
    else if (cont[i].which_builtin == 3) // sin hacer todavia
    {
        printf("custom pwd\n"); // ver funcion getcwd
        custom_pwd();
    }
    else if (cont[i].which_builtin == 4)
    {
        printf("custom export\n");
        custom_export(cont);
    }
    exit (1);

}

void execute_command(t_content *cont, int i)
{
    if (cont[i].builtin == 1)
    {
        exec_builtin(cont, i);
    }
    else
    {
        //printf("comando normal\n"); /bin/ls
        execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
        // controlar error de este
        perror("command not found"); // hardcodeado
        printf("Error: %s\n", strerror(errno));
        //ft_putstr_fd("%s: command not found\n", 2);

        exit(EXIT_FAILURE);
        //ft_putstr_fd("Error: Command does not exist.\n", 2);
        //return ;
    }
}

