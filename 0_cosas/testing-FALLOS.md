

# Trying to list a non-existent directory
ls non_existent_directory


# Copying a non-existent file
cp non_existent_file.txt destination.txt


# Moving a non-existent file
mv non_existent_file.txt newname.txt


# Trying to remove a non-existent file
rm non_existent_file.txt

# Trying to remove a directory without -r option
rm directory_to_remove/

##################### TODO OK HASTA AQUI PERO no se quien esta imprimiendo el error
##########################################
##########################################
##########################################

# Redirecting output of a non-existent command
non_existent_command > output.txt
# CORREGIR EL ERROR NO SALE IGUAL A BASH


# Using a variable that is not defined
echo $undefined_variable
# ESTO ACARABAN LO MIRA


echo "un texto sin comilla final
# ESTO ACARABAN LO MIRA


# exit codes 
ls non_existent_directory
echo $?

ver con caraban como actualizar la variable $?
https://vscode.dev/github/acaraban/public_minishell/blob/8981c4eae4a1bd811a75fc780501b4b915300b87/err_mngment/err_execve.c#L34




# asignar variables no funciona
name="John"
echo "Hello, $name!"


# Quoting
echo "This is a double-quoted string: \"Hello\""
echo "This is an escaped \$ sign: \$"






