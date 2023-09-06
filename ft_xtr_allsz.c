#include "minishell.h"

void free_dbl(char **new)
{
	int h;

	h = 0;
	while (new[h])
		free (new[h++]);
	free(new[h]);
	free(new);
}

char **ft_xtr_allsz(char **arr, char **add, int posadd)
{
	char **jj;
	int i;
	int h;
	int l;
	int k;

	i = 0;
	h = 0;
	l = 0;
	k = 0;
	while (arr[i] )
		i++;
	while (add[h + posadd])
		h++;
	jj = (char **)ft_calloc(sizeof(char *), i + h + 1);
	jj[h + i] = NULL;
	while (l < h + i)
	{
		if (l < i)
		{
			jj[l] = arr[l];
		}
		else
		{
			jj[l] = add[k + posadd];
			k++;
		}
		l++;
	}
	free_dbl(arr);
	return (jj);
}

/*int main(void)
{
	int i;
	char **jj;
	char **arr;
	char **fin;

	i = 0;
	jj = (char **)ft_calloc(sizeof(char *), 4);
	jj[3] = NULL;
	arr = (char **)ft_calloc(sizeof(char *), 5);
	arr[4] = NULL;
	jj[0] = strdup("primera linea jj");
	jj[1] = strdup("segunda linea jj");
	jj[2] = strdup("tercera linea jj");
	arr[0] = strdup("arr linea primera");
	arr[1] = strdup("arr linea segunda");
	arr[2] = strdup("arr linea tercera");
	arr[3] = strdup("arr linea cuarta");
	fin = ft_xtr_allsz(jj, arr, 2);
	while (fin[i])
		printf("%s\n", fin[i++]);
}*/