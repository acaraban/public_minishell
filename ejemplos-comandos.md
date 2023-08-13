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



if (access(argv[argc - 1], F_OK) != 0 || access(argv[argc - 1], W_OK) == 0)
		data->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	else if (access(argv[argc - 1], W_OK) != 0)
	{
		perror(argv[argc - 1]);
		exit(1);
	}
	if (data->outfile < 0)
		exit(1);


****************************************************************************

# ejemplo "con outfile"
# con 2 comandos

*******************************

ls -l | grep mini > otro.txt

ls -l > otro.txt | wc -l < otro.txt





*************************

# ejemplo "con outfile"
# con 2 comandos

*******************************








****************************************************************************

/* ejemplos de comandos con fallos a proposito para que saquen error */

*****************************************************************************


wc -l < forever.md | grep minni < forever.md | cati -e