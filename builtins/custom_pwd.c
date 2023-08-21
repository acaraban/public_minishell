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
