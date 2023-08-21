#include "../minishell.h"



void custom_env(t_content *cont, int i)
{
    ft_dbl_printf("", cont[i].global->env, "\n", 1);
}