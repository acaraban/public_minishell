#include "../minishell.h"

/*
    When changing directory there are different errors to print.
    e.g. cd non_existing_dir
    e.g. cd dir_without_permissions
    Handle this error messages with perror() function.
*/

void change_dir(t_content *cont, int i)
{
    if (chdir(cont->custom->command_arg) == 0)
    {
        if (cont->custom->is_switch == 1)
            update_environment_old(cont, i, cont->custom->current_pwd);
        cont->custom->current_pwd = custom_return_pwd();
        update_environment_new(cont, i, cont->custom->current_pwd);
    }
    else
    {
        ft_putstr_fd("minishell: ", 2);
        perror(ft_strjoin(ft_strjoin(cont[i].cmd, ": "), cont[i].full_comand[1]));
        cont->global->err_stat = 1;
    }
    free(cont->custom->current_pwd);
}

void update_last_pwd(t_content *cont, int i)
{
    cont->custom->last_pwd = custom_return_pwd();
    update_environment_old(cont, i, cont->custom->last_pwd);
    free(cont->custom->last_pwd);
}

void init_custom_cd_values(t_content *cont, int i)
{
    cont->custom->command_arg = cont[i].full_comand[1];
    cont->custom->last_pwd = calloc(256, sizeof(char));
    cont->custom->is_switch = 0;
    if (!cont->custom->last_pwd)
        return ;
    cont->custom->current_pwd = calloc(256, sizeof(char));
    if (!cont->custom->current_pwd)
        return ;
}

/*
    Function to execute the chdir -- change directory.
    "command_arg" is already valid if reaches this function.
    Before chdir, saving current pwd as oldpwd and update OLDPWD env.
    After chdir, get current pwd and update PWD environment variable.
    IMPT: free last_pwd after use, to avoid segmentation faults.
    If cd - gets executed before changing dir, there is no OLDPWD yet.
    e.g. bash: cd: OLDPWD not set
*/

void custom_cd(t_content *cont, int i)
{
    cont->custom = (t_custom *)malloc(sizeof(t_custom) * 1);
    init_custom_cd_values(cont, i);
    if (ft_strcmp(cont->custom->command_arg, "") == 0 || ft_strcmp(cont->custom->command_arg, "~") == 0)
        cont->custom->command_arg = getenv("HOME");
    if (ft_strcmp(cont->custom->command_arg, "-") == 0)
    {
        cont->custom->current_pwd = custom_return_pwd();
        cont->custom->command_arg = get_the_oldpwd(cont, i);
        if (ft_strcmp(cont->custom->command_arg, "") == 0)
        {
            ft_putstr_fd(ft_strjoin("minishell: ", ft_strjoin(cont[i].cmd, ": OLDPWD not set\n")), 2);
            return;
        }
        cont->custom->is_switch = 1;
    }
    else
        update_last_pwd(cont, i);
    change_dir(cont, i);
    return ;
}
