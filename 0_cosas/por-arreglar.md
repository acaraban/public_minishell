
cuando hay varias redirecciones de salida hay que crear archivos vacios
cuando hay error cambiar la variable err_stat
imprimir los errores con la funcion perror o sterror
redireccion de salida al principio del comando no va > loquesea
# OLDPWD esta en las variables de entorno desde el principio
cuando inicie minishell ejecutar algo que lo quite
# Using a variable that is not defined
echo $undefined_variable




builtins con redirecciones: export y unset



# resultados diferentes en bash y en minishell
echo "Hello
(faltan las >) y luego no cierra con Ctrl + D



## voy por :
https://chat.openai.com/c/ddd2925d-21f9-4172-a935-2c572d16edab

# Redirecting output of a non-existent command
non_existent_command > output.txt
## no consigo hacer un print de esto por la salida de error
https://vscode.dev/github/acaraban/public_minishell/blob/42625720e0c92c7cdf17681058feedfa1d7d7766/err_mngment/err_execve.c#L17



###
shell level de bash y minishell






###################

echo hola | exit




#
ls >
bash: syntax error near unexpected token `newline'
pero minishell no protesta, ni tampoco crea ningun archivo

minishell deberia decir que hay error sintactico
bash-3.2$ ls >
bash: syntax error near unexpected token `newline'






# 1 Mensajes de error de execve





# 3 Imprimir mensajes de errores

el mensaje de error debe ser distinto
https://vscode.dev/github/acaraban/public_minishell/blob/cf5e5544b2f3249e3917f0f97c1f49b158b9235c/err_mngment/err_stx.c#L10



# Builtin / CD #

OLDPWD al iniciar minishell no debe existir y generarse al cambiar de dierctorio además de actualizar PWD

# Builtin / echo #

echo a '' b '' c '' d | cat -e          expected: a  b  c  d$ sin ningún null 
echo -n bonjour -n                      expected: bonjour -n

# Builtin / Exit #
exit ' 3'                           expected: $?=3  (Exit elimina por delante los isspaces)
exit '3 '                           expected: $?=3  (por detras solo elimina el espacio y la tabulacion)
exit '3\r'                          expected: minishell: exit: 3\r: numeric argument required

# 5 hay funciones muy largas
ft_specials.c

# 6 minishell dentro de minishell
hay que hacerlo??

# de la hoja de evaluacion 
lo de ejecutar espacios y tabs, funciona diferente al darte a elegir si display todas las opciones o no

# leaks

# norminette
