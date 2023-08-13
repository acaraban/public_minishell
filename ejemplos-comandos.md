****************************************************************************

 ejemplos de comandos "sin infile ni outfile"
 solo 3 comandos

*****************************************************************************



ls -l | grep mini | cat -e

ping -c 5 claudiajuan.com | grep rtt | cat -e

# resultados ok, pero tarda mucho en cerrarse y volver a salir minishell>

# puede que sea porque no tengo puestos los waitpid
# hecho!! :)


****************************************************************************

# ejemplos de comandos "con infile" pero no outfile
# solo 3 comandos

*****************************************************************************

# infile en primer comando

grep estamos < forever.md | wc -l | cat -e

# resultados distintos, en bash 1 linea, en minishell 2 lineas
#hecho!! :)

grep hoy < forever.md | grep feria < forever.md | wc -w
# perfecto


# infile en segundo comando

wc -l < forever.md | grep minni < forever.md | cat -e

grep hoy | grep feria < forever.md | wc -w
ping -c 5 claudiajuan.com | grep rtt | cat -e


ls | grep feria < forever.md | wc -w
ls | grep feria < forever.md | wc -w | cat -e


# infile en primer y segundo comandos

grep hoy < forever.md | grep feria < forever.md | wc -w


grep hoy < forever.md | grep feria < forever.md | wc -w | cat -e

# infile en los 3 comandos
grep hoy < forever.md | grep feria < forever.md | grep semana < forever.md

# infile en los 4 comandos
grep hoy < forever.md | grep feria < forever.md | grep semana < forever.md | grep gusta < forever.md


xx en el ultimo un infile

****************************************************************************

# ejemplos de comandos "con infile" pero no outfile
# con 4 comandos

*****************************************************************************

grep hoy < forever.md | grep feria < forever.md | wc -w | cat -e

# funciona perfe (pero no ha comprobado el segundo)


****************************************************************************

/* ejemplos de comandos con fallos a proposito para que saquen error */

*****************************************************************************


wc -l < forever.md | grep minni < forever.md | cati -e