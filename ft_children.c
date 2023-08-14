#include "minishell.h"

void execute_first_child(t_content *cont, int i, int (*fds)[2])
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
        write_on_the_pipe(fds, i);
    execute_command(cont, i);
}