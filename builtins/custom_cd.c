#include "../minishell.h"

/*
    Function to execute the chdir -- change directory.
    "command_arg" is already valid if reaches this function.
    Before chdir, saving current pwd as oldpwd and update OLDPWD env.
    After chdir, get current pwd and update PWD environment variable.
    IMPT: free old_pwd after use, to avoid segmentation faults.
*/


void custom_cd(t_content *cont, int i)
{
    char *command_arg;
    char *new_pwd;
    char *old_pwd;

    command_arg = cont[i].full_comand[1];
    new_pwd = calloc(sizeof(char), 100);
    if (!new_pwd)
        return ;
    old_pwd = calloc(sizeof(char), 100);
    if (!old_pwd)
        return ;
    if (ft_strcmp(command_arg, "") == 0 || ft_strcmp(command_arg, "~") == 0)
    {
        //printf("vacio o virgulilla dentro del if\n");
        command_arg = getenv("HOME");
    }
    if (ft_strcmp(command_arg, "-") == 0)
    {
        command_arg = getenv("OLDPWD");
    }
    old_pwd = custom_return_pwd();
    update_environment_old(cont, i, old_pwd);
    free(old_pwd);
    if (chdir(command_arg) == 0)
    {
        printf("succes changing dir\n");
        new_pwd = custom_return_pwd();
        update_environment_new(cont, i, new_pwd);
        free(new_pwd);
    }
    else
    {
        printf("error dir\n");
    }
    return ;
}
