#include "minishell.h"

void init_numstring_vars(int *comp, int *cles, int *i)
{
    *comp = 0;
	*cles = 0;
	*i = 0;
}

int check_match(char *s1, int *i, t_content *cont)
{
    if (find_match(s1, *i, s1[*i]) < 0)
    {
        err_stx("error sintactico\n", cont);
        return (1);
    }
    return (0);
}