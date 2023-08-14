#include "minishell.h"

void	ft_executor(t_content *cont)
{
    int i;
    pid_t pid;
    //printf("empiezo\n");
    //printf("numero de comandos\n"); // falta que me pase el numero de comandos
    int num_of_commands; // tmp
    

    i = 0;
    num_of_commands = cont[i].global->num_cmd;
    int fds[num_of_commands][2];
    

    cont->global->environ_path = ft_env_path(cont->global->env);
    //printf("environ path %s\n", cont->global->environ_path);

    while (i < num_of_commands)
    {
        //printf("cmd %s %d\n", cont[i].cmd, i);
        cont[i].builtin = 0;
        cont[i].which_builtin = 0;
        //printf("which cmd: %d\n", cont[i].which_builtin);
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
                //printf("primer child\n");
                if (cont[i].infile)
                {
                    manage_infiles(cont, i);
                }
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                //printf("access path %s\n", cont[i].access_path); // comprobar builtin o  no
                // gestionar que haya un outfile
                if (cont[i].outfile)
                {
                    manage_outfiles(cont, i);
                }
                // comprobar si es builtin antes del dup2 ?? no se seguro si tiene que ser antes del dup2
                if (is_builtin(cont, i) == 0)
                {
                    //printf("es un builtin\n");
                    //printf("el comando es: %s\n", cont[i].cmd);
                    cont[i].builtin = 1; // tmp
                }
                // si solo hay un comando, la salida no debe ser el pipe, sino el stdout
                // si hay mas de 1 comando y no hay fichero de salida, que escriba en el pipe
                if ((num_of_commands > 1) && !(cont[i].outfile))
                {
                    write_on_the_pipe(fds, i);
                }
                // aqui ya todo sale por el pipe, no se ve en consola
                execute_command(cont, i);
            }
            // si NO es el primer child ni el ultimo
            else if (i > 0 && i < num_of_commands -1)
            {
                //printf("second child\n");
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                //printf("access path %s\n", cont[i].access_path); // comprobar builtin o  no
                if (cont[i].infile)
                {
                    manage_infiles(cont, i);
                }
                else // sino, que coja info del child anterior
                {
                    read_from_the_pipe(fds, i);
                }
                // child escribe, y como no es el ultimo, escribe en el end write del siguiente pipe
                // o en el outfile si lo hubiera
                if (cont[i].outfile)
                {
                    manage_outfiles(cont, i);
                }
                else // si no hay outfile, escribe en el write end del pipe
                {
                    write_on_the_pipe(fds, i);
                }
                execute_command(cont, i); 
            }
            // si es el ultimo child, que escriba en la salida estandar o en el outfile
            else if (i == num_of_commands - 1)
            {
                // last child
                //printf("last child\n");
                cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
                //printf("access path %s\n", cont[i].access_path); // built in or not
                if (cont[i].infile)
                {
                    manage_infiles(cont, i);
                }
                else
                {
                    read_from_the_pipe(fds, i);
                }
                
                // si hubiera outfile, que salga por ahi
                if (cont[i].outfile)
                {
                    manage_outfiles(cont, i);
                }
                // sino tiene outfile, saldra por la salida estandar xq es el ultimo                
                execute_command(cont, i);
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
