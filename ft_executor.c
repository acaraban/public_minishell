#include "minishell.h"

void	ft_executor(t_content *cont)
{
    int i;
    pid_t pid;
    //printf("empiezo\n");
    //printf("numero de comandos\n"); // falta que me pase el numero de comandos
    int num_of_commands; // tmp


    i = 0;
    num_of_commands = 3; // tmp
    int fds[num_of_commands][2]; // tmp num of commands var

    

    cont->global->environ_path = ft_env_path(cont->global->env);
    //printf("environ path %s\n", cont->global->environ_path);

    while (i < num_of_commands)
    {
        //printf("cmd %s\n", cont[i].cmd);
        if (pipe(fds[i]) == -1) // controlar error del pipe -1
        {
            return ;
        }
        //printf("fds[%d][0]: %d\n", i, fds[i][0]);
        //printf("fds[%d][1]: %d\n", i, fds[i][1]);

        pid = fork();
        // controlar error -1
        if (pid == -1)
        {
            return ;
        }
        if (pid == 0)
        {
            if (i == 0) // si es el primer child
            {
                //printf("primer child\n");
                /* infile stuff */
                if (cont[i].infile)
                {
                    //printf("infile: %s\n", cont[i].infile);
                    cont->infile_fd = open(cont->infile, O_RDONLY);
                    //printf("infile descriptor number %d\n", cont->infile_fd);
                    if (cont->infile_fd)
                    {
                        dup2(cont->infile_fd, STDIN_FILENO);
                        close(cont->infile_fd);
                    }
                }
                dup2(fds[i][1], STDOUT_FILENO); // redir standar input
                close(fds[i][1]); // cierra duplicado
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                //printf("access path %s\n", cont[i].access_path);
                execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
                // controlar error de este
                ft_putstr_fd("Error: Command does not exist.\n", 2); // pero debe sacar otro mensaje en bash
		        return ;
            }
            // si NO es el primer child ni el ultimo
            else if (i > 0 && i < num_of_commands -1)
            {
                //printf("second child\n");
                // si hay infile que coja info del infile
                if (cont[i].infile)
                {
                    //printf("infile: %s\n", cont[i].infile);
                    cont->infile_fd = open(cont->infile, O_RDONLY);
                    //printf("infile descriptor number %d\n", cont->infile_fd);
                    if (cont->infile_fd)
                    {
                        dup2(cont->infile_fd, STDIN_FILENO);
                        close(cont->infile_fd);
                    }
                }
                else
                {
                    // sino, que coja info del child anterior
                    dup2(fds[i - 1][0], STDIN_FILENO);
                    close(fds[i - 1][0]);
                }
                // child escribe, y como no es el ultimo, escribe en el end write del siguiente pipe
                dup2(fds[i][1], STDOUT_FILENO);
                close(fds[i][1]); // cierra duplicado
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                //printf("access path %s\n", cont[i].access_path);
                execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
                // controlar error de este
                ft_putstr_fd("Error: Command does not exist.\n", 2);
		        return ;
            }
            // si es el ultimo child, que escriba en la salida estandar o en el outfile
            else if (i == num_of_commands - 1)
            {
                // last child
                //printf("last child\n");
                // si hay infile que coja info del infile
                if (cont[i].infile)
                {
                    //printf("infile: %s\n", cont[i].infile);
                    cont->infile_fd = open(cont->infile, O_RDONLY);
                    //printf("infile descriptor number %d\n", cont->infile_fd);
                    if (cont->infile_fd)
                    {
                        dup2(cont->infile_fd, STDIN_FILENO);
                        close(cont->infile_fd);
                    }
                }
                else
                {
                    // que coja info del child anterior
                    dup2(fds[i - 1][0], STDIN_FILENO);
                    close(fds[i - 1][0]);
                }
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                //printf("access path %s\n", cont[i].access_path);
                execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
                // controlar error de este
                ft_putstr_fd("Error: Command does not exist.\n", 2);
		        return ;
            }
            else // quitar esto
            {
                perror("No debe llegar\n");
                exit(-1);
            }
        }
        // main, cierra escritura
        if (i > 0 && i < num_of_commands)
        {
            close(fds[i - 1][0]);
        }
        if (i < num_of_commands - 1)
            close(fds[i][1]);

        i++;
    }
}