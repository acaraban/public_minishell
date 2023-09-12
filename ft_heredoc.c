#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	ft_heredoc(char **arr, t_content *cont)
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
	new = (char *)ft_calloc(sizeof(char), 1);
	val = (char *)ft_calloc(sizeof(char), 1);
	fd = 0;
	//signal(SIGINT, handle_sigint);
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
				free (aux);
				if (new)
					aux = ft_strjoin(new, val);
				else
					aux = ft_strdup(val);
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
		if (!val || cont->global->err_stat == 1)
		{
			free(val);
			free (new);
			ft_printf("exit\n");
			return (0);
		}
		if (pos_char(val, '$'))
		{
			aux = ft_add_varent(val, pos_char(val, '$'), cont[0].global[0].env, cont);
			free (val);
			val = aux;
			aux = NULL;
		}
		if (!ft_strcmp(arr[i], val))
			i++;
	}
	free (val);
	//ft_printf("este es new: %s\n", new);
	fd = open(".awdrgyj123.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, new, ft_strlen(new));
	free (new);
	close(fd);
	return (1);
}