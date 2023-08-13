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


void manage_outfiles(t_content *cont, int i)
{
    // if first child
    printf("outfile is: %s\n", cont[i].outfile);
    // abrir en modo append o en modo sobreescribir
    if (cont[i].tfl == 1) // modo sobre escribir
    {
        cont->outfile_fd = open(cont[i].outfile, O_TRUNC | O_CREAT | O_RDWR, 0644); // no tengo claro porque RDWR
    }
    else if (cont[i].tfl == 2) // modo append
    {
        cont->outfile_fd = open(cont[i].outfile, O_APPEND | O_CREAT | O_RDWR, 0644);
    }
    // como ha habido outfile, tiene que escribir en el fichero de salida
    dup2(cont->outfile_fd, STDOUT_FILENO);
    close(cont->outfile_fd); // cierra duplicado
}


