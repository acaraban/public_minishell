#include "../minishell.h"


void custom_pwd(void)
{
	char *buff;
	size_t size;

	size = 1024;
	buff = malloc(sizeof(size));
	if (buff == NULL)
	{
		return ;
	}
	if (getcwd(buff, size) == NULL)
	{
		perror("getcwd");
		return ;
	}
	else
	{
		printf("%s\n", buff);
	}
	free(buff);
}


/*
	otra para coger el resultado
*/

char *custom_return_pwd(void)
{
	char *buff;
	size_t size;

	size = 1024;
	buff = malloc(sizeof(size));
	if (buff == NULL)
	{
		return (NULL);
	}
	if (getcwd(buff, size) == NULL)
	{
		perror("getcwd");
		return (NULL);
	}
	else
	{
		printf("%s\n", buff);
	}
	//free(buff);
	return (buff);
}