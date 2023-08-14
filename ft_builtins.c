#include "minishell.h"

/* Function to check if comand is a builtin. */

int is_builtin(t_content *cont, int i)
{
    // if cont[i].cmd  == "echo" por ejemplo
    printf("el comando que llega es: %s\n", cont[i].cmd);
    if (ft_strnstr(cont[i].cmd, "echo", 4))
    {
        printf("dentro de ft_strnstr\n");
        return (0);
    }
    else if (ft_strnstr(cont[i].cmd, "pwd", 3))
    {
        //mini_pwd();
        printf("execute mini pwd\n");
        return(0);
    }
    else
    {
        return (1); // temporal
    }
}

//void exec_builtin(t_content *cont, int i)
void exec_builtin(void)
{
    //execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
    printf("dentro de exec  builtin\n");
    custom_pwd();
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