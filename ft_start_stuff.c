#include "minishell.h"

/*
    When minishell starts, environment variables should not include OLDPWD.
    Function to search for it and delete it.
    After that modify all the other items indexes to make the array shorter.
*/

void ft_delete_env_oldpwd(t_content *cont)
{
    int index;
    int j;
	
	j = 0;
    while(cont->global->env[j])
    {
        
        if (ft_strncmp(cont->global->env[j], "OLDPWD", 6) == 0)
        {
            free(cont->global->env[j]);
            index = j;
        }
        j++;
    }
    while(cont->global->env[index])
    {
        cont->global->env[index] = cont->global->env[index + 1];
        index++;
    }
}