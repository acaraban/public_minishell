# OLDPWD esta desde el principio
cuando inicie minishell ejecutar algo que lo quite



# resultados diferentes en bash y en minishell
echo "Hello
(faltan las >) y luego no cierra con Ctrl + D

#
ls >
bash: syntax error near unexpected token `newline'
pero minishell no protesta, ni tampoco crea ningun archivo

minishell deberia decir que hay error sintactico
bash-3.2$ ls >
bash: syntax error near unexpected token `newline'

# esto hay que mirarlo ?? 1> y 2>
ls non_existent_directory 1> output.txt 2> error.txt



# 1 Mensajes de error de execve



# 2
builtins con redirecciones: export y unset


# 3 Imprimir mensajes de errores

el mensaje de error debe ser distinto
https://vscode.dev/github/acaraban/public_minishell/blob/cf5e5544b2f3249e3917f0f97c1f49b158b9235c/err_mngment/err_stx.c#L10

https://vscode.dev/github/acaraban/public_minishell/blob/737f95d260ff59bb5de6bc7e497cbbdb0ff688b6/builtins/custom_cd.c#L14



https://vscode.dev/github/acaraban/public_minishell/blob/737f95d260ff59bb5de6bc7e497cbbdb0ff688b6/ft_exec_cmds.c#L123



https://vscode.dev/github/acaraban/public_minishell/blob/737f95d260ff59bb5de6bc7e497cbbdb0ff688b6/builtins/custom-cd_utils.c#L87



# 4

haciendo esto:
minishell>cd ~
minishell>cd -

despues de la virgulilla no actualiza bien el oldpath


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
