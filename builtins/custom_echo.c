#include "../minishell.h"

void custom_echo(t_content *cont, int i)
{
    ft_printf("%s", cont[i].full_comand[2]);
}