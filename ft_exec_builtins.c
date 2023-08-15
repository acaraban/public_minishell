#include "minishell.h"

/* Function to check if comand is a builtin. */

int is_builtin(t_content *cont, int i)
{
    //printf("el comando que llega es: %s\n", cont[i].cmd);
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

/* Function to execute the appropiate custom builtin command. */

void exec_builtin(t_content *cont, int i)
{
    if (cont[i].which_builtin == 1)
    {
        printf("voy a sacar echo\n");
        custom_echo(cont, i);
    }
    else if (cont[i].which_builtin == 3)
    {
        printf("custom pwd\n");
        custom_pwd();
    }
    exit (1);

}

void execute_command(t_content *cont, int i)
{
    if (cont[i].builtin == 1)
    {
        exec_builtin(cont, i);
    }
    else
    {
        //printf("comando normal\n"); /bin/ls
        execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
        // controlar error de este
        perror("command not found"); // hardcodeado
        printf("Error: %s\n", strerror(errno));
        //ft_putstr_fd("%s: command not found\n", 2);

        exit(EXIT_FAILURE);
        //ft_putstr_fd("Error: Command does not exist.\n", 2);
        //return ;
    }
}

/* temporales, hay que hacerlos y ponerlos en otra pagina */

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