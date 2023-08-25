#include "minishell.h"



/*
    num = index for the pipes file descriptors
*/

void	ft_executor(t_content *cont)
{
    int i;
    pid_t pid;
    int num_of_commands;
    int num;

    i = 0;
    num_of_commands = cont[i].global->num_cmd;
    int fds[num_of_commands][2];
    cont->global->environ_path = ft_env_path(cont->global->env);
    
    while (i < num_of_commands)
    {
        // check if command is builtin without redirs
        if (is_builtin_noredir(cont, i) == 0)
        {
            //printf("just started: es un builtin with no redires\n");
            // enviar el comando a una funcion, que es el builtin tal cual, 
            // ejecutandose en el padre directamente
            // aqui llega desde el custom_cd, y debe parar, no seguir para abajo
            return ;
        }
        // antes del fork, comprobar que builtins no tienen redirecciones y cuales si 
        // ejecutar algunos builtins (cd, pwd, exit) y tener en cuenta los dups
        cont[i].builtin = 0;  // se podria iniciar estas en funcion aparte
        cont[i].which_builtin = 0;
        num = i;
        if (pipe(fds[i]) == -1)
            return ;
        pid = fork();
        if (pid == -1)
            return ;
        if (pid == 0)
            ft_execute_child(cont, i, fds, num);
        main_closes_pipes(cont, i, fds, num);
        waitpid(pid, NULL, 0);
        i++;
    }
}
// ************* POR HACER *************

/* se podria mejorar poniendo los perror de los pipe y de los fork
pero entonces me paso de lineas y hay que quitar todas las inicializaciones
del principio y ponerlas en otra funcion */