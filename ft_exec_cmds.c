#include "minishell.h"


/* 
    Function to check if the command is a built-in without redirs.
    cd : check if command is cd and if args for cd are valid or included in the built-in
         if yes, execute custom_cd function
         if not, execute cd command with execve
    exit
*/

int is_builtin_noredir(t_content *cont, int i)
{
    printf("inside function is_builtin_noredir\n");
    if (ft_strcmp(cont[i].full_comand[0], "cd") == 0) // si el comando es cd
    {
        printf("dentro del builtin cd\n");
        // comprueba si cd tiene argumento
        if (cont[i].full_comand[1])
        {
            // y si es valido
            if (arg_is_valid(cont[i].full_comand[1]) == 0)
            {
                printf("hay un argumento para cd\n");
                custom_cd(cont[i].full_comand[1]);
            }
        }
        // si no tiene argumento cd, me lo han pasado a secas
        else
        {
            printf("sin argumento para cd\n");
            cont[i].full_comand[1] = ""; // como no tiene, lo creo pero vacio
        }
        custom_cd(cont[i].full_comand[1]);
        return (0);
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "exit") == 0) && (cont[i].full_comand[1] == NULL))
    {
        exit(0);
    }
    printf("no es ningun builtin_noredir\n");
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
        printf("dentro de echo, son iguales y el segundo arg es -n\n");
        cont[i].which_builtin = 1;
    }
    else if ((ft_strcmp(cont[i].full_comand[0], "pwd") == 0) && (cont[i].full_comand[1] == NULL))
    {
        printf("dentro de pwd, no tiene flags\n");
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
        printf("dentro de env, no tiene flags\n");
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
        printf("custom pwd\n");
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
        printf("custom env\n");
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
        //printf("comando normal\n"); /bin/ls
        execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
        // controlar error de este
        // perror("command not found"); // hardcodeado
        printf("Error: %s\n", strerror(errno));
        //ft_putstr_fd("%s: command not found\n", 2);

        exit(EXIT_FAILURE);
        //ft_putstr_fd("Error: Command does not exist.\n", 2);
        //return ;
    }
}

