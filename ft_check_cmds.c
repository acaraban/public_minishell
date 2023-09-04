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
    Function to check if the options received when exit is called are numeric.
    And handle error appropiately.
    e.g. bash: exit: algo: numeric argument required
*/

void check_options(char *options, char *cmd)
{
    int i;

    i = 0;
    while(options[i])
    {
        if (ft_isdigit(options[i]) == 1)
        {
            printf("exit\n");
            exit (0);
        }
        else
        {
            printf("exit\n");
            ft_putstr_fd("minishell: ", 2);
            ft_putstr_fd(ft_strjoin(ft_strjoin(ft_strjoin(cmd, ": "), options), ": numeric argument required\n"), 2);
            exit (EXIT_FAILURE);
        }
        i++;
    }
}