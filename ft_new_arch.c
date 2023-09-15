/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_arch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:04 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:22:34 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    nombrearchivo --> name of the file to create
    If there are not rights to write on the file, this is error msg:
    e.g. bash: <filename>: Permission denied
*/

int	new_arch(char *name)
{
	char	*namfile;
	int		descfile;

	namfile = ft_strdup(name);
	descfile = open(namfile, O_WRONLY | O_CREAT, 0644);
	if (descfile == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(namfile);
		ft_free (namfile);
		return (0);
	}
	ft_free (namfile);
	close(descfile);
	return (1);
}

int	ft_tam_args(char *txt, t_global *glb)
{
	int	i;
	int	tam;

	i = 0;
	tam = 1;
	while (txt[i])
	{
		if (txt[i] == '|')
			tam++;
		if (txt[i] == '\"' || txt[i] == '\'')
		{
			if (find_match(txt, i, txt[i]) < 0)
			{
				ft_printf("error sintactico\n");
				glb->err_stat = STX_ERR;
				ft_free (txt);
				return (-1);
			}
			i += find_match(txt, i, txt[i]);
		}
		i++;
	}
	return (tam);
}

char	**convert_str_trim(char **vue)
{
	int		i;
	char	*aux;

	i = 0;
	while (vue[i])
	{
		aux = ft_strdup(vue[i]);
		ft_free (vue[i]);
		vue[i] = ft_strtrim(aux, " ");
		ft_free (aux);
		i++;
	}
	return (vue);
}
