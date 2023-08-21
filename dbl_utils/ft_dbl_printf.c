#include "../minishell.h"

void	ft_dbl_printf(char *txt, char **arr, char *ftxt, int sal)
{
	int i;

	i = 0;
	if (!sal && txt)
		ft_printf("%s", txt);
	while (arr[i])
	{
		if (sal && txt)
			ft_printf("%s", txt);
		ft_printf("%s", arr[i++]);
		if (ftxt)
			ft_printf("%s", ftxt);
	}
}