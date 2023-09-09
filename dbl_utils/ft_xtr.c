#include "../minishell.h"

char **dobl_prt_free(char **arr, char *txt, int inicial, int conta)
{
	char **jj;
	int i;
	int h;

	i = 0;
	h = 0;
	if (arr[0] == NULL)
	{
		jj = (char **)calloc(sizeof(char *), 2);
		jj[0] = (char *)calloc(sizeof(char ), conta - inicial + 2);
		jj[1] = NULL;
	}
	else
	{
		while (arr[i])
			i++;
		jj = (char **)calloc(sizeof(char *), i + 2);
		jj[i] = (char *)calloc(sizeof(char ), conta - inicial + 2);
		jj[i + 1] = NULL;
		while (h < i)
		{
			jj[h] = strdup(arr[h]);
			h++;
		}
	}
	h = 0;
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

/*int main(void)
{
	atexit(func_free);
	char **arr;
	int i;
	i = 0;
	char txt[] = "esto es el texto de prueba, donde tengo que comprobar \
	que el texto se corta en las partes adecuadas";

	arr = (char **)ft_calloc(sizeof(char *), 1);
	arr[0] = NULL;
	arr = dobl_prt(arr, txt, 0, 5);
	arr = dobl_prt(arr, txt, 6, 8);
	arr = dobl_prt(arr, txt, 9, 15);
	arr = dobl_prt(arr, txt, 16, 24);
	arr = dobl_prt(arr, txt, 25, 30);
	while (arr[i])
		printf("%s\n", arr[i++]);
	i = 0;
	while (arr[i])
		free (arr[i++]);
	free(arr);
}*/
