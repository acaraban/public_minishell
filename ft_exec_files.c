#include "minishell.h"

/*
    REDIRECTIONS:
    Child reads from different sources depending on the situation:
    - from the standard input
    - from the pipe of previous child
    - from the infile if there is one
    If there is no infile, program does not reach this function
*/

void manage_infiles(t_content *cont, int i)
{
    cont->infile_fd = open(cont[i].infile, O_RDONLY); 
    if (cont->infile_fd == -1)
    {
        handle_execve_error_message(cont, i);
        exit (EXIT_FAILURE);
    }
    if (cont->infile_fd && cont[i].nfl == 1)
    {
        dup2(cont->infile_fd, STDIN_FILENO);
        close(cont->infile_fd);
    }
    else if (cont->infile_fd && cont[i].nfl == 2)
    {
        dup2(cont->infile_fd, STDIN_FILENO);
        close(cont->infile_fd);
        if (unlink(cont[i].infile) != 0)
            perror("unlink");
    }
}

/*
    Print message when error in outfile.
    Another way to print the same:
    e.g. printf("minishell: %s: %s\n", cont[i].outfile, strerror(errno));
*/

void print_outfile_error(t_content *cont, int i)
{
    ft_putstr_fd("minishell: ", 2);
    perror(cont[i].outfile);
    exit (EXIT_FAILURE);
}

/*
    REDIRECTIONS:
    Child writes in a different place depending on the situation:
    - in the standard output
    - in the pipe
    - in a file
    Redirections on a file has two cases: > (truncate mode) and >> (append mode)
    If tfl == 0 no need to do any redir.
    If the file for the output redirection does not exist or does not have 
    writing permissions, handle error appropiately.
*/

void manage_outfiles(t_content *cont, int i)
{
    if (cont[i].tfl == 1)
    {
        if (access(cont[i].outfile, F_OK) != 0 || access(cont[i].outfile, W_OK) == 0)
        {
            cont->outfile_fd = open(cont[i].outfile, O_TRUNC | O_CREAT | O_RDWR, 0644);
            if (cont->outfile_fd == -1)
                print_outfile_error(cont, i);
        }
        else if (access(cont[i].outfile, W_OK) != 0)
            print_outfile_error(cont, i);
    }
    else if (cont[i].tfl == 2)
    {
        if (access(cont[i].outfile, F_OK) != 0 || access(cont[i].outfile, W_OK) == 0)
        {
            cont->outfile_fd = open(cont[i].outfile, O_APPEND | O_CREAT | O_RDWR, 0644);
            if (cont->outfile_fd == -1)
                print_outfile_error(cont, i);
        }
        else if (access(cont[i].outfile, W_OK) != 0)
            print_outfile_error(cont, i);
    }
    dup2(cont->outfile_fd, STDOUT_FILENO);
    close(cont->outfile_fd);
}
