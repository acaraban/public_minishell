#include "minishell.h"

void execute_command(t_content *cont, int i)
{
    if (cont[i].builtin == 1)
    {
        exec_builtin(cont, i);
    }
    else
    {
        printf("comando normal\n");
        execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
    }
}

/* Function to check if comand is a builtin. */

int is_builtin(t_content *cont, int i)
{
    //printf("el comando que llega es: %s\n", cont[i].cmd);
    //if (ft_strnstr(cont[i].cmd, "echo", 4))
    if (ft_strnstr(cont[i].full_comand[0], "echo", 4) && ft_strnstr(cont[i].full_comand[1], "-n", 2) && cont[i].full_comand[2] && !cont[i].full_comand[3])
    {
        printf("dentro de echo\n");
        cont[i].which_builtin = 1;
        return (0);
    }
    else if (ft_strnstr(cont[i].cmd, "pwd", 3))
    {
        //printf("yes, soy built in: %s\n", cont[i].cmd);
        cont[i].which_builtin = 3;
        return(0);
    }
    return (1);
}

void exec_builtin(t_content *cont, int i)
{
    if (cont[i].which_builtin == 1)
    {
        printf("voy a sacar echo\n");
        custom_echo(cont, i);
    }
    else if (cont[i].which_builtin == 3)
    {
        custom_pwd();
        //exit (1);
    }
    exit (1);

}

/* temporales, hay que hacerlos */

int	custom_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	ft_putendl_fd(buf, 1);
	free(buf);
	return (0);
}

void custom_echo(t_content *cont, int i)
{
    ft_printf("%s", cont[i].full_comand[2]);
   /* char *args[4];
    char *pru;
    char **envp;

    printf("dentro custom echo\n");
    pru = strdup("/bin/echo");
    args[0] = strdup("echo");
    args[1] = strdup("-n");
    args[2] = strdup("hola");
    args[3] = NULL;
    envp = NULL;
    execve(pru, args, envp);*/

}