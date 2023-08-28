#include "../minishell.h"

/*
	This function gets the OLDPWD of the minishell program.
	getenv() function gets the OLDPWD of the mac.
*/

char * get_the_oldpwd(t_content *cont, int i)
{
	char *old_pwd;
	int j;
	
	j = 0;
	old_pwd = calloc(sizeof(char), 100);
    if (!old_pwd)
        return (NULL);
	while(cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "OLDPWD", 6) == 0)
		{
			old_pwd = ft_strcpy(old_pwd, cont[i].global->env[j]); // funcionaba con strcpy
			//printf("cogiendo old pwd: %s\n", old_pwd);
			old_pwd = ft_strchr(old_pwd, '/');
			//printf("recortando old pwd: %s\n", old_pwd);
		}
		j++;
	}
	return (old_pwd);

}
/*	
	Function to find the OLDPWD environment variable and set the new value.
*/

void update_environment_old(t_content *cont, int i, char *old_pwd)
{
	int j;
	
	j = 0;
	while(cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "OLDPWD", 6) == 0)
		{
			//printf("update OLDPWD\n");
			cont[i].global->env[j] = ft_strjoin("OLDPWD=", old_pwd);
		}
		j++;
	}
}

/*
	Function to find the PWD environment variable and set the new value.
	new_pwd is the updated path after chdir
*/

void update_environment_new(t_content *cont, int i, char *new_pwd)
{
	int j;

	j = 0;
	while(cont[i].global->env[j])
	{
		if (ft_strncmp(cont[i].global->env[j], "PWD", 3) == 0)
		{
			//printf("update PWD\n");
			cont[i].global->env[j] = ft_strjoin("PWD=", new_pwd);
		}
		j++;
	}
}

/*
	Check if argument received is a valid path.
	The opendir function takes a single argument: the name of the directory
	you want to open. It returns a pointer to a DIR structure, which is an
	opaque data type representing the opened directory stream. 
	If the directory cannot be opened, it returns a NULL pointer.
*/

int arg_is_a_path(char *comand_args)
{
	if (opendir(comand_args) == NULL)
	{
		printf("error opening dir\n");
		return (1); // si da error, la funcion is_builtin ya no lo considera builtin
		// y saldra el error del execve ejecutando cd
		// ese error no exactamente igual
		// bash dice : bash: cd: algo: No such file or directory
		// minishell dice: /usr/bin/cd: line 4: cd: algo: No such file or directory
		// esto gestionarlo mejor, porque si es un builtin, lo que esta mal es la ruta
		
	}
	printf("success opening dir\n");
	return (0);
}
/*
	Function to check if arg for cd is valid.
	Success returns 0.
	After checking if arg is valid, custom cd is executed.
	And after need to update env var PWD
*/

int arg_is_valid(char *command_arg)
{
	if (ft_strcmp(command_arg, "~") == 0)
	{
		return (0); 
	}
	if (ft_strcmp(command_arg, "-") == 0)
	{
		return (0);
	}
	if (arg_is_a_path(command_arg) == 0)
	{
		return (0);
	}
	return (0);
}
