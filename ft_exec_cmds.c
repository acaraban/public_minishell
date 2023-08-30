#include "minishell.h"

/*
    If cmd starts with '/' its considered an absolute path and returns 1.
    Returns 0 if cmd is just the command without path. E.g. ls
*/

int cmd_has_path(t_content *cont, int i)
{
    int j;

    j = 0;
    if ((cont[i].cmd[j]) == '/')
    {
        return (1);
    }
    return (0);
}

/*
    Function to check if command received is actually a program.
    e.g. ./program-name
*/

int cmd_is_program(t_content *cont, int i)
{
    int j;

    j = 0;
    if (cont[i].cmd[0] == '.' && cont[i].cmd[1] == '/')
    {
        return (1);
    }
    return (0);
}

/*
    Function to check if command received has an absolute path or not.
    It not, get the path to access the program from the environment vars.
    Check also if instead of a path, there is a program e.g: ./program-name
*/

void check_for_path(t_content *cont, int i)
{
    if (cmd_is_program(cont, i) == 1)
    {
        cont[i].access_path = cont[i].cmd;
        cont[i].full_comand[0] = cont[i].cmd;
    }
    else if (cmd_has_path(cont, i) == 1)
    {
        cont[i].access_path = cont[i].cmd;
    }
    else
    {
        cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
    }
}

/* 
    Function to check if the command is a built-in without redirs.
    cd : check if command is cd and args are valid or included in the built-in
         if so, execute custom_cd function; if not, execute cd command with execve
    exit : exit main process with 0 for a clean exit
*/

int is_builtin_noredir(t_content *cont, int i)
{
    char *extra;
    size_t size;

    extra = malloc(sizeof(size));
	size = 1024;
    if (ft_strcmp(cont[i].full_comand[0], "cd") == 0)
    {
        if (cont[i].full_comand[1])
        {
            if (arg_is_valid(cont[i].full_comand[1]) != 0)
                return (1);
        }
        else
            cont[i].full_comand[1] = "";
        custom_cd(cont, i);
        return (0);
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "exit") == 0) && (cont[i].full_comand[1] == NULL))
        exit(0);
        //custom_exit();
    return (1);
}

/*
Function to check if the command is a built-in. 
◦ echo con la opción -n. -------hecho
◦ cd solo con una ruta relativa o absoluta. -------hecho, falta que el mensaje de error del execve coincida con bash
◦ pwd sin opciones.  -------hecho
◦ export sin opciones. 
◦ unset sin opciones.
◦ env sin opciones o argumentos. -------hecho
◦ exit sin opciones. -------hecho
*/

int is_builtin(t_content *cont, int i)
{
    if ((ft_strcmp(cont[i].full_comand[0], "echo") == 0) && (strcmp(cont[i].full_comand[1], "-n") == 0))
    {
        cont[i].which_builtin = 1;
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "pwd") == 0) && (cont[i].full_comand[1] == NULL))
    {
        cont[i].which_builtin = 3;
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "export") == 0) && (cont[i].full_comand[1] == NULL))
    {
        printf("dentro de export, no tiene flags\n");
        cont[i].which_builtin = 4;
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "unset") == 0) && (cont[i].full_comand[1] == NULL))
    {
        printf("dentro de unset, no tiene flags\n");
        cont[i].which_builtin = 5;
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "env") == 0) && (cont[i].full_comand[1] == NULL))
    {
        cont[i].which_builtin = 6;
    }
    else
    {
        return (1);
    }
    return(0);
}

/* Function to execute the appropiate custom built-in command. */

void exec_builtin(t_content *cont, int i)
{
    if (cont[i].which_builtin == 1)
    {
        //printf("execute custom echo\n");
        custom_echo(cont, i);
    }
    else if (cont[i].which_builtin == 3)
    {
        //printf("custom pwd\n");
        custom_pwd();
    }
    else if (cont[i].which_builtin == 4)
    {
        printf("custom export\n");
        //custom_export();
    }
    else if (cont[i].which_builtin == 5)
    {
        printf("custom unset\n");
        //custom_unset();
    }
    else if (cont[i].which_builtin == 6)
    {
        //printf("custom env\n");
        custom_env(cont, i);
    }
    exit (1);
}

/* Function to execute the bash command or the custom built-in. */

void execute_command(t_content *cont, int i)
{
    if (cont[i].builtin == 1)
    {
        exec_builtin(cont, i);
    }
    else
    {
        // comprobar commando, viene con ruta o suelto
        //printf("access path: %s\n", cont[i].access_path);
        //printf("full_comand: %s\n", cont[i].full_comand[1]);
        if (execve(cont[i].access_path, cont[i].full_comand, cont->global->env) == -1)
        {
            printf("errno sería: %d\n", errno);
            handle_execve_error_message(errno, cont, i);
            //perror("execve"); // this prints a descriptive error message
            // Handle the error appropriately
        }
        exit(EXIT_FAILURE);
    }
}

