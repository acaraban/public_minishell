#include "../minishell.h"


void custom_pwd(void)
{
	char *buff;
	size_t size;

	size = 1024;
	buff = malloc(size);
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
	Function to get the pwd as a string
*/

char *custom_return_pwd(void)
{
	char *buff;
	size_t size;

	size = 1024;
	buff = malloc(size);
	if (buff == NULL)
	{
		return (NULL);
	}
	if (getcwd(buff, size) == NULL)
	{
		perror("getcwd");
		return (NULL);
	}
	//free(buff);
	return (buff);
}