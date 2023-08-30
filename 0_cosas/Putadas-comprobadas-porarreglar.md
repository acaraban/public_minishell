### Putadas de Corrección Minishell-42 ###
----------------
----------------
# Redireciones: 
----------------
----------------

##### FAIL
echo Hola Bernardo! > "mira que chulo $USER"
——se ejecuta ok, pero quieres borrar el archivo creado con rm y empiezas a escribir el nombre del archivo, te lo autocompleta pero luego la minishell no te lo reconoce
——bash te hace esto: rm mira\ que\ chulo\ msintas-
———pero minishell hace: rm mira que chulo msintas- 
—-y entonces no lo borra, porque ese archivo no existe, considera que cada palabra es un archivo y no los encuentra
minishell>rm mira que chulo msintas- 
rm: mira: No such file or directory
rm: que: No such file or directory
rm: chulo: No such file or directory
rm: msintas-: No such file or directory


###### FAIL
echo hola > que > tal
—bash crea dos ficheros, que y tal
— minishell solo crea uno, tal

##### CORRECTO
echo bonjour >> test'sticked'

######  FAIL
echo > test > je bonjour > suis
---- bash crea 3 ficheros output, pero rellena el ultimo.
minishell solo crea y rellena el ultimo

#### CORRECT
echo hola> ‘que tal’ amigo
echo hola> que tal amigo

#### fail
> test"sticked" echo bonjour

#### fail
> test echo bonjour > je > suis
minishell no crea todos los ficheros, solo el ultimo y lo rellena bien

### fail
echo >> test bonjour > je > suis

### fail
echo bonjour > a'b'c'd'e'f'g'h'i'j'k'l'm'n'o'p'q'r's't'u'v'w'x'y'z'
### fail
echo bonjour > a'b'c"d"e'f'g"h"i'j'k"l"m'n'o"p'q'r"s't'u"v"w"x"y'z'

### fail
echo foo >>>>> bar
mensaje de error no esta bien

### fail
> test
segmentation fault

## me la salto
[SETUP echo a > a] echo bonjour >> a

### ok
echo hola2 > "srcs/a"

## ok
echo prueba > /Users/msintas-/Documents/Cursus42/

## fail
>
>>
debe dar error sintactico
>>>
>>>>
sacamos error pero el mensaje no esta igual

## ok
echo bonjour "> out"
echo hola "> que tal" > bonjour

## fail
cat <<< "hola que tal"
esto no es error sintactico, debe funcionar

## fail
cat << < bar
debe dar error sintactico y nos da segmentation fault


# Variables entorno: # y # CMD && Status #
no compruebo todavia, ver con acaraban


------------------
# Builtin / CD #
------------------

## ok
Cd ..
cd ..
cd .
cd
# comprobar esto
siempre salen con $?=0
# por hacer
OLDPWD al iniciar minishell no debe existir y generarse al cambiar de dierctorio además de actualizar PWD


------------------
# Builtin / echo #
------------------

### fail
echo a '' b '' c '' d | cat -e
echo -n bonjour -n 
le falta el ultimo -n
echo '' '' ''
al probar con echo '' '' '' | cat -e , se ve que no ha puesto los espacios

## ok
echo lalalala                lalalalal      alalalalal
echo bonjour -n
echo -n bonjour -n

## sin probar
[EXPORTS PATH='/bin:/usr/bin'] Echo bonjour     expected: bonjour$
[UNSET PATH] Echo bonjour               expected: minishell: Echo: command not found $?=127



-------------------
# Builtin / Exit #
-------------------

## fail
exit ' 3'
exit '3 '
exit '3\r'
