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


# infile en segundo comando
ls | grep feria < forever.md | wc -w
ls | grep feria < forever.md | wc -w | cat -e


# infile en primer y segundo comandos
grep hoy < forever.md | grep feria < forever.md | wc -w
grep hoy < forever.md | grep feria < forever.md | wc -w | cat -e
wc -l < forever.md | grep minni < forever.md | cat -e
wc -l < forever.md | grep minni < forever.md | wc -w | cat -e
## perfecto


# infile en los 4 comandos

grep hoy < forever.md | grep feria < forever.md | grep gusta < forever.md | wc -w


# outfile en primer comando
# con 3 comandos


ls -l > probando.md | grep ft < probando.md | cat -e
# ok resultado pero bash avisa de que no existia el fichero
# y minishell no avisa, lo hace todo


# con 3 comandos
# outfile en primer comando y en ultimo, infile en todos
grep hoy < forever.md > mas.md | grep feria < mas.md | grep gusta < mas.md > quepasa.md
# bash protesta porque dice que no existe mas.md
bash: mas.md: No such file or directory
bash: mas.md: No such file or directory
# minishell lo hace bien

grep hoy < forever.md >> mas.md | grep feria < mas.md | grep gusta < mas.md >> quepasa.md








ping -c 5 claudiajuan.com | grep rtt | cat -e








grep hoy < forever.md | grep feria < forever.md | wc -w | cat -e

# infile en los 3 comandos
grep hoy < forever.md | grep feria < forever.md | grep semana < forever.md

# infile en los 4 comandos
grep hoy < forever.md | grep feria < forever.md | grep semana < forever.md | grep gusta < forever.md


xx en el ultimo un infile
grep hoy < forever.md | grep feria < forever.md | grep semana < forever.md

****************************************************************************

# ejemplos de comandos "con infile" pero no outfile
# con 4 comandos

*****************************************************************************

grep hoy < forever.md | grep feria < forever.md | wc -w | cat -e

# funciona perfe (pero no ha comprobado el segundo)



****************************************************************************

# ejemplos de comandos "con infiles y outfiles"
# con 3 y 4 comandos

*******************************

ls -l > resultado.txt | grep mini < resultado.txt | grep ft < resultado.txt > final.txt






****************************************************************************

# ejemplo "con outfile"
# con 2 comandos

*******************************

ls -l | grep mini > otro.txt

ls -l > otro.txt | wc -l < otro.txt


***********************************************************





****************************************************************************

# ejemplos de comandos con fallos a proposito para que saquen error 

*****************************************************************************


wc -l < forever.md | grep minni < forever.md | cati -e