#include "../minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

char **start_end_pip(char **vue, t_content *cont)
{
	int i;
	int h;
	char *readli;
	char *camb;
	char **new;
	char **aux;

	i = 0;
	h = 0;
	while (vue[i])
		i++;
	if (vue[i - 1][0] == '|')
	{
		while (vue[i - 1][0] == '|')
		{
			camb = readline(">");
			readli = ft_strtrim(camb, " ");
			free(camb);
			while (readli[h])
				h++;
			new = ft_specials(readli, cont, 0);
			if (new == NULL)
				return (NULL);
			aux = ft_xtr_allsz_free(vue, new, 0);
			free_dbl(vue);
			vue = aux;
			while (vue[i])
				i++;
			free (readli);
			free_dbl(new);
		}
	}
	return (vue);
}