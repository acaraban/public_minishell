#include "minishell.h"

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
    else if ((ft_strcmp(cont[i].full_comand[0], "export") == 0))
    {
        custom_export(cont, i);
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "exit") == 0))
    {
        if (cont[i].full_comand[1])
        {
            check_options(cont[i].full_comand[1], cont[i].cmd);
        }
        printf("exit\n");
        exit(0);
    }
	  else if ((ft_strcmp(cont[i].full_comand[0], "unset") == 0))
    {
        custom_unset(cont, i);
    }
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
        printf("execute custom echo\n");
        custom_echo(cont, i);
    }
    else if (cont[i].which_builtin == 3)
    {
        //printf("custom pwd\n");
        custom_pwd();
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
        //printf("access path: %s\n", cont[i].access_path);
        //printf("full_comand: %s\n", cont[i].full_comand[1]);
        if (execve(cont[i].access_path, cont[i].full_comand, cont->global->env) == -1)
        {
            handle_execve_error_message(cont, i);
        }
        ft_putstr_fd("he llegado al final\n", 2);
        exit(EXIT_FAILURE);
    }
}

