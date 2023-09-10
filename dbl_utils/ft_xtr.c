#include "../minishell.h"

int the_arr_dbl(char **arr, char **jj, int conta, int inicial)
{
	int i;
	int h;

	i = 0;
	h = 0;
	if (arr[0] == NULL)
	{
		jj = (char **)ft_calloc(sizeof(char *), 2);
		jj[0] = (char *)ft_calloc(sizeof(char ), conta - inicial + 2);
		jj[1] = NULL;
	}
	else
	{
		while (arr[i])
			i++;
		jj = (char **)ft_calloc(sizeof(char *), i + 2);
		jj[i] = (char *)ft_calloc(sizeof(char ), conta - inicial + 2);
		jj[i + 1] = NULL;
		while (h < i)
		{
			jj[h] = ft_strdup(arr[h]);
			h++;
		}
	}
	return (i);
}

char **dobl_prt_free(char **arr, char *txt, int inicial, int conta)
{
	char **jj;
	int i;
	int h;

	i = 0;
	h = 0;
	jj = NULL;
	i = the_arr_dbl(arr, jj, conta, inicial);
	while (h + inicial < conta + 1)
	{
		jj[i][h] = txt[h + inicial];
		h++;
	}
	h = 0;
	if (arr[0] != NULL)
	{
		while (h < i + 1)
			free (arr[h++]);
	}
	free (arr);
	return (jj);
}
