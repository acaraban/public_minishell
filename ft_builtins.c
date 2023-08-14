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
        printf("yes, soy built in.\n");
        //cont[i].specials->which_cmd = 1;
        //exec_builtin(cont, i);
        return(0);
    }
    else
    {
        return (1); // temporal
    }
}

void exec_builtin(void)
//void exec_builtin(t_content *cont, int i)
{
    /*char *args[3];
    char **envp;

    args[0] = "/bin/pwd";
    args[1] = NULL;
    args[2] = NULL;
    envp = NULL;
    execve(args[0], args, envp);*/
    //printf("dentro de exec builtin cmd: %s\n", cont[i].cmd);
    custom_pwd();
    ft_putstr_fd("after dup2 llega ?????\n", 2);
    exit (1);
    /*if (cont[i].specials->which_cmd == 1)
    {
        printf("execute custom pwd\n");
        custom_pwd();
    }*/
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