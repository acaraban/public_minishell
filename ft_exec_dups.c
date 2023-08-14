#include "minishell.h"

void write_on_the_pipe(int (*fds)[2], int num)
{
    dup2(fds[num][WRITE_END], STDOUT_FILENO); // redir standar output
    close(fds[num][WRITE_END]); // cierra duplicado
}

void read_from_the_pipe(int (*fds)[2], int num)
{
    dup2(fds[num - 1][READ_END], STDIN_FILENO);
    close(fds[num - 1][READ_END]);
}