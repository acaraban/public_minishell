#include "../minishell.h"

/*
    El command_arg ya es algo valido cuando llega aqui
    Function to execute the chdir -- change directory
*/

void custom_cd(char *command_arg)
{
    printf("inside custom cd function\n");
    // caso cd ó cd ~
    if (ft_strcmp(command_arg, "") == 0 || ft_strcmp(command_arg, "~") == 0)
    {
        printf("vacio o virgulilla dentro del if\n");
        command_arg = getenv("HOME");
    }
    // para que este funcione, habria que actualizar la variable de entorno OLDPWD
    // porque sino me coge siempre desde donde empecé
    if (ft_strcmp(command_arg, "-") == 0)
    {
        command_arg = getenv("OLDPWD");
    }


//
    if (chdir(command_arg) == 0)
    {
        printf("succes changing dir\n");
        printf("chdir dice command arg es: %s\n", command_arg);
    }
    else
    {
        printf("error dir\n");
    }
    return ;
}




