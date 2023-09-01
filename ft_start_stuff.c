#include "minishell.h"

/*
    When minishell starts, environment variables should not include OLDPWD.
    Function to search for it and delete it.
    Before deletion and modifing all other item indexes, reorder to send
    After that modify all the other items indexes to make the array shorter.
*/

void ft_delete_env_oldpwd(char **environment)
{
    int index;
    int j;
	
	j = 0;
    while(environment[j])
    {
        
        if (ft_strncmp(environment[j], "OLDPWD", 6) == 0)
        {
            free(environment[j]);
            index = j;
        }
        j++;
    }
    while(environment[index])
    {
        environment[index] = environment[index + 1];
        index++;
    }
    /*j = 0;
    while(environment[j])
    {
        printf("dime: %s\n", environment[j]);
        j++;
    }*/
}