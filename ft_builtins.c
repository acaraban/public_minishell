#include "minishell.h"

/* Function to check if comand is a builtin. */

int is_builtin(t_content *cont, int i)
{
    // if cont[i].cmd  == "echo" por ejemplo
    printf("el comando que llega es: %s\n", cont[i].cmd);
    if (ft_strnstr(cont[i].cmd, "echo", 4))
    {
        printf("dentro de echo\n");
        //cont[i].which_builtin = 1;
        return (0);
    }
    else if (ft_strnstr(cont[i].cmd, "pwd", 3))
    {
        printf("yes, soy built in.\n");
        printf("yes, built in: %s\n", cont[i].cmd);
        cont[i].which_builtin = 3;
        return(0);
    }
    return (1);
}

//void exec_builtin(void)
void exec_builtin(t_content *cont, int i)
{
    if (cont[i].which_builtin == 3)
    {
        custom_pwd();
        exit (1);
    }
}

/* temporal */

int	custom_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putendl_fd(buf, 1);
	free(buf);
	return (0);
}