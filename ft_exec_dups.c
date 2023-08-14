#include "minishell.h"

/* 
    Function to write on the WRITE END of actual pipe.
    Writes info so next child can get it from the pipe.
*/
void write_on_the_pipe(int (*fds)[2], int num)
{
    dup2(fds[num][WRITE_END], STDOUT_FILENO); // redir standar output
    close(fds[num][WRITE_END]); // cierra duplicado
}

/* 
    Function to read from READ END of previous pipe.
    Gets info from previous child.
*/

void read_from_the_pipe(int (*fds)[2], int num)
{
    dup2(fds[num - 1][READ_END], STDIN_FILENO);
    close(fds[num - 1][READ_END]);
}