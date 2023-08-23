#include "../minishell.h"

/*
    El command_arg ya es algo valido cuando llega aqui
    Function to execute the chdir -- change directory

    Impt: chdir cambia el directorio pero hay que actualizar
    la variable de entorno OLDPWD
    Cuando cd navega a un sitio, guarda esa ruta en PWD 
    y en OLDPWD se esta guardando la ultima visitada
*/

//void custom_cd(char *command_arg)
void custom_cd(t_content *cont, int i)
{
    char *command_arg;
    char *new_pwd;
    size_t size;

    command_arg = cont[i].full_comand[1];
    new_pwd = malloc(sizeof(size));
	size = 1024;
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

    if (chdir(command_arg) == 0)
    {
        printf("succes changing dir\n");
        // cuando cambie de directorio debe:
        // actualizar las variables de entorno
        // PWD y OLDPWD
        new_pwd = custom_return_pwd(); // esta es mi nueva ruta after chdir
        printf("NEW pwd: %s\n", new_pwd);
        printf("but actual PWD env: %s\n", getenv("PWD"));
        update_environment(cont, i, new_pwd);
        //setenv("");
        // 
        // se puede recorrer como un array todas las env
        // y accediendo a cada una para sobreescribirle el valor
        printf("chdir dice command arg es: %s\n", command_arg);
    }
    else
    {
        printf("error dir\n");
    }
    return ;
}
