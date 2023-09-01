#include "../minishell.h"

/*
    execve returns -1 in case of an error. And retrieves an specific error
    code stored in the errno variable. Handle every error and print proper
    message.
    The messages should be printed in the error output, and not stdout
    otherwise gets redirected with dup2 to the pipe and nothing is printed
    in the console.
*/



/*
    Errno 14 necesita otro mensaje distinto ya que el error verdadero
    sería otro. Cuando el comando no existe, debe decir command not found,
    en lugar de Bad Adress, pero execve ejecuta un path y por eso da error 14

*/

//void handle_execve_error_message(int error_number, t_content *cont, int i)
void handle_execve_error_message(t_content *cont, int i)
{
    // 14 -- Bad address PERO yo quiero sacar otro mensaje distinto
    if (errno == EFAULT) 
    {
        // bash: foo: command not found
        // comando que no existe redirigirlo a un output
        // e.g non_existe_command > output.txt
        // No se puede usar perror porque el error 14 no saca el mensaje que quiero
        ft_putstr_fd("minishell: ", 2);
        ft_putstr_fd(ft_strjoin(cont[i].cmd, ": command not found\n"), 2);
        // update exit status after executing command
        cont->global->err_stat = 127; // esto no actualiza nada
    }
    /* 
        Al error 2 ENOENT se llega con un comando asi: 
        wc -l < input.txt
        pasa por ft_exec_files.c primero
    */
    else if (errno == ENOENT) // 2
    {
        // bash: cd: kfjasldja: No such file or directory
        ft_putstr_fd("minishell: ", 2);
        perror(cont[i].infile);
    }
    else if (errno == EACCES) // 13 -- Permission denied
    {
        // bash: entrada.md: Permission denied
        // bash: cd: carpeta/: Permission denied
        ft_putstr_fd("minishell: ", 2);
        if (cont[i].infile)
        {
            perror(cont[i].infile);
        }
        else
        {
        // aqui llego intentando ejecutar un programa sin permisos de ejecucion
            perror(cont[i].cmd);
        }
    }
    // este exit no se si hace falta
    //exit (EXIT_FAILURE);
}