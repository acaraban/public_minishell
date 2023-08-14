#include "minishell.h"

void execute_first_child(t_content *cont, int i, int (*fds)[2], int num)
{
    if (cont[i].infile)
        manage_infiles(cont, i);
    cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
    if (cont[i].outfile)
        manage_outfiles(cont, i);
    // comprobar si es builtin antes del dup2 ?? no se seguro si tiene que ser antes del dup2
    if (is_builtin(cont, i) == 0)
        cont[i].builtin = 1;
    if ((cont[i].global->num_cmd > 1) && !(cont[i].outfile))
        write_on_the_pipe(fds, num);
    execute_command(cont, i);
}


void execute_middle_children(t_content *cont, int i, int (*fds)[2], int num)
{
    cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
    //printf("access path %s\n", cont[i].access_path); // comprobar builtin o  no
    if (cont[i].infile)
    {
        manage_infiles(cont, i);
    }
    else // sino, que coja info del child anterior
    {
        read_from_the_pipe(fds, num);
    }
    // child escribe, y como no es el ultimo, escribe en el end write del siguiente pipe
    // o en el outfile si lo hubiera
    if (cont[i].outfile)
    {
        manage_outfiles(cont, i);
    }
    else // si no hay outfile, escribe en el write end del pipe
    {
        write_on_the_pipe(fds, num);
    }
    execute_command(cont, i);
}
void execute_last_child(t_content *cont, int i, int (*fds)[2], int num)
{
    //printf("last child\n");
    cont[i].access_path = ft_access_program(cont->global->environ_path, cont[i].cmd);
    //printf("access path %s\n", cont[i].access_path); // built in or not
    if (cont[i].infile)
    {
        manage_infiles(cont, i);
    }
    else
    {
        read_from_the_pipe(fds, num);
    }
    
    // si hubiera outfile, que salga por ahi
    if (cont[i].outfile)
    {
        manage_outfiles(cont, i);
    }
    // sino tiene outfile, saldra por la salida estandar xq es el ultimo                
    execute_command(cont, num);
}