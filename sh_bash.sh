#!/bin/bash

arch0=$(find . \( -type d -name "libft" -o -type d -name "get_next_line" -o -type d -name "ft_printf" \) -prune -o -type f -name "*.c" -print | sed 's/\.\///g')

cell=$(echo "$arch0" | xargs)

echo "SRCS = $cell" > comodin.txt

grep -v "SRCS = " Makefile >> comodin.txt

cat comodin.txt > Makefile

rm comodin.txt

############################################################

echo "#ifndef MINISHELL_H
#define MINISHELL_H

#include \"libft/libft.h\"
#include \"get_next_line/get_next_line.h\"
#include \"ft_printf/ft_printf.h\"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <string.h>

//valido
# define VLD 0
//comando no encontrado
# define NOT_FND 127
//error sintactico
# define STX_ERR 2

typedef struct s_global
{
	int tam;
	char **env;
	int err_stat;
	int new_stat;
}t_global;

typedef struct s_content
{
	char *cmd;
	char **full_comand;
	char *infile;
	char *outfile;
	int nfl;
	int tfl;
	t_global *global;
}t_content;
" > minishell.h

for palabra in $arch0; do
    ./sh_busqueda_cabeceras.sh $palabra >> minishell.h
done

echo "
#endif" >> minishell.h