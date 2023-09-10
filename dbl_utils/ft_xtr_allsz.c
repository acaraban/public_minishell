#include "../minishell.h"

void	free_dbl(char **new)
{
	int	h;

	h = 0;
	while (new[h])
		free (new[h++]);
	free(new[h]);
	free(new);
}

void	init_xtrallsz_values(int *i, int *h, int *l, int *k)
{
	i = 0;
	h = 0;
	l = 0;
	k = 0;
}

int	set_i_value(int *i, char **arr)
{
	int	n;

	n = *i;
	while (arr[n])
	{
		i++;
	}
	return (n);
}

char	**ft_xtr_allsz_free(char **arr, char **add, int posadd)
{
	char	**jj;
	int		i;
	int		h;
	int		l;
	int		k;

	init_xtrallsz_values(&i, &h, &l, &k);
	i = set_i_value(&i, arr);
	while (add[h + posadd])
		h++;
	jj = (char **)ft_calloc(sizeof(char *), i + h + 1);
	jj[h + i] = NULL;
	while (l < h + i)
	{
		if (l < i)
			jj[l] = ft_strdup(arr[l]);
		else
		{
			jj[l] = ft_strdup(add[k + posadd]);
			k++;
		}
		l++;
	}
	free_dbl(arr);
	return (jj);
}
