#include "../minishell.h"

/*
    Function to execute the chdir -- change directory.
    "command_arg" is already valid if reaches this function.
    Before chdir, saving current pwd as oldpwd and update OLDPWD env.
    After chdir, get current pwd and update PWD environment variable.
    IMPT: free last_pwd after use, to avoid segmentation faults.
*/


void custom_cd(t_content *cont, int i)
{
    char *command_arg;
    char *last_pwd;
    char *current_pwd;

    command_arg = cont[i].full_comand[1];
    last_pwd = calloc(sizeof(char), 100);
    if (!last_pwd)
        return ;
    current_pwd = calloc(sizeof(char), 100); // mejorar estos calloc
    if (!current_pwd)
        return ;
    if (ft_strcmp(command_arg, "") == 0 || ft_strcmp(command_arg, "~") == 0)
    {
        //printf("vacio o virgulilla dentro del if\n");
        command_arg = getenv("HOME");
        printf("command arg de home: %s\n", command_arg);
    }
    // guardo el actual para que luego sea el antiguo
    
    if (ft_strcmp(command_arg, "-") == 0)
    {
        printf("-------\n");
        // 1 - Save PWD
        current_pwd = custom_return_pwd();
        printf("current_pwd: %s\n", current_pwd);
        //update_environment_old(cont, i, last_pwd);
        // 2 - go to OLDPWD
        command_arg = get_the_oldpwd(cont, i);
        printf("command_arg es old pwd: %s\n", command_arg);
       
        if (chdir(command_arg) == 0)
        {
            printf("succes changing dir\n");
            // pero antes me guardo el actual para que sea el last de nuevo
            //last_pwd = strcpy(last_pwd, command_arg);
            update_environment_old(cont, i, current_pwd);
            current_pwd = custom_return_pwd(); // ahora cambia
            update_environment_new(cont, i, current_pwd);
            //
            // estos actualizan normal el PWD
            //update_environment_old(cont, i, last_pwd);
            //update_environment_new(cont, i, command_arg);
            //free(current_pwd); // no free aqui, porque da error free algo que se usa despues
        }
        else
        {
            printf("error dir\n");
        }
    }
    else
    {
        last_pwd = custom_return_pwd();
        printf("last_pwd: %s\n", last_pwd);
        update_environment_old(cont, i, last_pwd);
        if (chdir(command_arg) == 0)
        {
            printf("succes changing dir\n");
            current_pwd = custom_return_pwd();
            update_environment_new(cont, i, current_pwd);
            free(current_pwd); // no free aqui, porque da error free algo que se usa despues
        }
        else
        {
            printf("error dir\n");
        }
    }
    //free(last_pwd);
    return ;
}
//update_environment_old(cont, i, last_pwd);
//free(last_pwd);