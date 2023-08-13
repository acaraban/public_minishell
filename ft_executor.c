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
    printf("environ path %s\n", cont->global->environ_path);

    while (i < num_of_commands)
    {
        printf("cmd %s %d\n", cont[i].cmd, i);
        if (pipe(fds[i]) == -1) // controlar error del pipe -1
        {
            return ;
        }
        //printf("fds[%d][0]: %d\n", i, fds[i][0]);
        //printf("fds[%d][1]: %d\n", i, fds[i][1]);

        pid = fork();
        if (pid == -1) // controla error
        {
            return ;
        }
        if (pid == 0)
        {
            if (i == 0) // si es el primer child
            {
                printf("primer child\n");
                /* infile stuff */
                if (cont[i].infile)
                {
                    manage_infiles(cont, i);
                }
                printf("antes de dup2 \n");
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                printf("access path %s\n", cont[i].access_path); // comprobar builtin o  no
                // gestionar que haya un outfile
                if (cont[i].outfile)
                {
                    manage_outfiles(cont, i);
                    /*printf("outfile is: %s\n", cont[i].outfile);
                    // abrir en modo append o en modo sobreescribir
                    if (cont[i].tfl == 1) // modo sobre escribir
                    {
                        cont->outfile_fd = open(cont[i].outfile, O_TRUNC | O_CREAT | O_RDWR, 0644); // no tengo claro porque RDWR
                    }
                    else if (cont[i].tfl == 2) // modo append
                    {
                        cont->outfile_fd = open(cont[i].outfile, O_APPEND | O_CREAT | O_RDWR, 0644);
                    }
                    // como ha habido outfile, tiene que escribir en el fichero de salida
                    dup2(cont->outfile_fd, STDOUT_FILENO);
                    close(cont->outfile_fd); // cierra duplicado*/
                }
                // si solo hay un comando, la salida no debe ser el pipe, sino el stdout
                // si hay mas de 1 comando y no hay fichero de salida, que escriba en el pipe
                if ((num_of_commands > 1) && !(cont[i].outfile))
                {
                    dup2(fds[i][WRITE_END], STDOUT_FILENO); // redir standar output
                    close(fds[i][WRITE_END]); // cierra duplicado
                }
                
                execve(cont[i].access_path, cont[i].full_comand, cont->global->env); 
                // controlar error de este, pero debe sacar otro mensaje en bash
                //ft_putstr_fd("Error: Command does not exist.\n", 2);
		        //return ;
            }
            // si NO es el primer child ni el ultimo
            else if (i > 0 && i < num_of_commands -1)
            {
                printf("second child\n");
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                printf("access path %s\n", cont[i].access_path); // comprobar builtin o  no
                // si hay infile que coja info del infile
                if (cont[i].infile)
                {
                    manage_infiles(cont, i);
                }
                else // sino, que coja info del child anterior
                {
                    dup2(fds[i - 1][READ_END], STDIN_FILENO);
                    close(fds[i - 1][READ_END]);
                }
                // child escribe, y como no es el ultimo, escribe en el end write del siguiente pipe
                // o en el outfile si lo hubiera
                if (cont[i].outfile)
                {
                    manage_outfiles(cont, i);
                }
                else // si no hay outfile, escribe en el write end del pipe
                {
                    dup2(fds[i][WRITE_END], STDOUT_FILENO);
                    close(fds[i][WRITE_END]); // cierra duplicado
                }
                
                execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
                // controlar error de este
                //ft_putstr_fd("Error: Command does not exist.\n", 2);
		        //return ;
            }
            // si es el ultimo child, que escriba en la salida estandar o en el outfile
            else if (i == num_of_commands - 1)
            {
                // last child
                printf("last child\n");
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                printf("access path %s\n", cont[i].access_path); // built in or not
                // si hay infile que coja info del infile
                if (cont[i].infile)
                {
                    manage_infiles(cont, i);
                }
                else
                {
                    // que coja info del child anterior
                    dup2(fds[i - 1][READ_END], STDIN_FILENO);
                    close(fds[i - 1][READ_END]);
                }
                
                // si hubiera outfile, que salga por ahi
                if (cont[i].outfile)
                {
                    manage_outfiles(cont, i);
                    /*printf("outfile is: %s\n", cont[i].outfile);
                    printf("y tipo de redir de salida es: %d\n", cont[i].tfl);
                    printf("y tipo de redir de entrada es: %d\n", cont[i].nfl);
                    // abrir en modo append o en modo sobreescribir
                    if (cont[i].tfl == 1) // modo sobre escribir
                    {
                        cont->outfile_fd = open(cont[i].outfile, O_TRUNC | O_CREAT | O_RDWR, 0644); // no tengo claro porque RDWR
                    }
                    else if (cont[i].tfl == 2) // modo append
                    {
                        cont->outfile_fd = open(cont[i].outfile, O_APPEND | O_CREAT | O_RDWR, 0644);
                    }
                    // child escribe, y es el ultimo, escribe en el fichero de salida
                    dup2(cont->outfile_fd, STDOUT_FILENO);
                    close(cont->outfile_fd); // cierra duplicado*/
                }
                // sino tiene outfile, saldra por la salida estandar xq es el ultimo                
                
                execve(cont[i].access_path, cont[i].full_comand, cont->global->env);
                // controlar error de este
                //ft_putstr_fd("Error: Command does not exist.\n", 2);
		        //return ;
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
            close(fds[i - 1][READ_END]);
        }
        if (i < num_of_commands - 1)
            close(fds[i][WRITE_END]);
        // waitpid
        waitpid(pid, NULL, 0);
        i++;
    }
}