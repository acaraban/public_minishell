#include "minishell.h"


void manage_infiles(t_content *cont, int i)
{
    printf("infile: %s\n", cont[i].infile);
    cont->infile_fd = open(cont[i].infile, O_RDONLY); // controlar error del open
    if (cont->infile_fd == -1) {
        perror("Failed to open the file");
        return ;
    }
    printf("infile descriptor number %d\n", cont->infile_fd);
    if (cont->infile_fd)
    {
        printf("inside if \n");
        dup2(cont->infile_fd, STDIN_FILENO);
        close(cont->infile_fd);
    }

}


/*void outfiles_management()
{

}*/


