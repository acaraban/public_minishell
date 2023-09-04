#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

void	ft_heredoc(char **arr)
{
	char *val;
	char *new;
	char *aux;
	int i;
	int r;
	int boo;
	int fd;

	i = 0;
	r = 0;
	boo = 0;
	new = (char *)calloc(sizeof(char), 1);
	val = (char *)calloc(sizeof(char), 1);
	//ft_dbl_printf("este es arr: \n", arr, "\n", 0);
	while (arr[i])
	{
		if (arr[i + 1] == NULL)
		{
			if (boo)
			{
				aux = (char *)calloc(sizeof(char), ft_strlen(val) + 2);
				while (val[r])
				{
					aux[r] = val[r];
					r++;
				}
				aux[r] = '\n';
				free (val);
				val = ft_strdup(aux);
				aux = ft_strjoin(new, val);
				free (new);
				new = ft_strdup(aux);
				free (aux);
				r = 0;
			}
			else
				boo = 1;
		}
		free (val);
		val = readline(">");
		if (!strcmp(arr[i], val))
			i++;
	}
	free (val);
	//ft_printf("este es new: %s\n", new);
	fd = open(".awdrgyj123.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, new, ft_strlen(new));
	close(fd);
}