#include "../minishell.h"


void change_dir(t_content *cont, int i, char *command_arg, int is_switch, char *current_pwd)
{
    if (chdir(command_arg) == 0)
    {
        if (is_switch == 1)
            update_environment_old(cont, i, current_pwd);
        current_pwd = custom_return_pwd();
        update_environment_new(cont, i, current_pwd);
    }
    else
        printf("error dir\n");
    free(current_pwd);
}

void update_last_pwd(t_content *cont, int i, char *last_pwd)
{
    last_pwd = custom_return_pwd();
    update_environment_old(cont, i, last_pwd);
    free(last_pwd);
}

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
    int is_switch;

    command_arg = cont[i].full_comand[1];
    last_pwd = calloc(256, sizeof(char));
    is_switch = 0;
    if (!last_pwd)
        return ;
    current_pwd = calloc(256, sizeof(char));
    if (!current_pwd)
        return ;
    if (ft_strcmp(command_arg, "") == 0 || ft_strcmp(command_arg, "~") == 0)
        command_arg = getenv("HOME");
    if (ft_strcmp(command_arg, "-") == 0)
    {
        current_pwd = custom_return_pwd();
        command_arg = get_the_oldpwd(cont, i);
        is_switch = 1;
    }
    else
        update_last_pwd(cont, i, last_pwd);
    change_dir(cont, i, command_arg, is_switch, current_pwd);
    return ;
}