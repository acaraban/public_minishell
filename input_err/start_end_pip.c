#include "../minishell.h"

char **start_end_pip(char **vue, t_content *cont)
{
	int i;
	int h;
	char *readli;
	char *camb;
	char **new;

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
			vue = ft_xtr_allsz(vue, new, 0);
			while (vue[i])
				i++;
			free (readli);
		}
	}
	return (vue);
}