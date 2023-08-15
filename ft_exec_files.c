#include "minishell.h"


void manage_infiles(t_content *cont, int i)
{
    //printf("infile: %s\n", cont[i].infile);
    cont->infile_fd = open(cont[i].infile, O_RDONLY); 
    if (cont->infile_fd == -1) // controla error del open
    {
        perror("Failed to open the file");
        return ;
    }
    //printf("infile descriptor number %d\n", cont->infile_fd);
    // comprobar si me pasan fichero sin < o con < (hace lo mismo)
    // lo anterior da error esto:  echo hola > outputi.txt | < outputi.txt grep hola | cat -e
    // se cree que hola en el segundo comando es el infile y son los args    
    //if (cont->infile_fd && (cont[i].nfl == 0 || cont[i].nfl == 1)) 
    // si == 0 significa que no tiene infile
    // si == 2 hacer lo mismo que == 1 pero luego borrar el archivo que me han pasado
    if (cont->infile_fd && cont[i].nfl == 1)
    {
        dup2(cont->infile_fd, STDIN_FILENO);
        close(cont->infile_fd);
    }
    else if (cont[i].nfl == 2)// me habrian pasado <<
    {
        printf("me han pasado <<, no se que hacer");
    }

}


void manage_outfiles(t_content *cont, int i)
{
    // if first child
    //printf("outfile is: %s\n", cont[i].outfile);
    // if tfl == 0 no hacer nada, dará error
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


