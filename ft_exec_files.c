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
    if (cont->infile_fd == -1) // controla error del open
    {
        printf("minishell: %s: No such file or directory\n", cont[i].infile);
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
            perror("Error unlinking the file");
    }
}


/*
    REDIRECTIONS:
    Child writes in a different place depending on the situation:
    - in the standard output
    - in the pipe
    - in a file
    Redirections on a file has two cases: > (truncate mode) and >> (append mode)
    If tfl == 0 no need to do any redir.
*/

void manage_outfiles(t_content *cont, int i)
{
    if (cont[i].tfl == 1)
    {
        cont->outfile_fd = open(cont[i].outfile, O_TRUNC | O_CREAT | O_RDWR, 0644); // no tengo claro porque RDWR
    }
    else if (cont[i].tfl == 2)
    {
        cont->outfile_fd = open(cont[i].outfile, O_APPEND | O_CREAT | O_RDWR, 0644);
    }
    dup2(cont->outfile_fd, STDOUT_FILENO);
    close(cont->outfile_fd);
}


