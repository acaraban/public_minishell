/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_dbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:50:17 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:50:18 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ft_dbl_strdup(char **arr)
{
	char	**saf;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	saf = (char **)ft_calloc(sizeof(char *), i + 1);
	saf[i] = NULL;
	i = 0;
	while (arr[i])
	{
		saf[i] = ft_strdup(arr[i]);
		i++;
	}
	return (saf);
}

char	**ft_dbl_strdup_str(char *txt)
{
	char	**asd;

	asd = (char **)ft_calloc(sizeof(char *), 2);
	asd[1] = NULL;
	asd[0] = ft_strdup(txt);
	return (asd);
}

char	**ft_elim_str_free(char **arr, int pos)
{
	int		i;
	int		j;
	char	**asd;

	i = 0;
	j = 0;
	while (arr[i])
		i++;
	asd = (char **)ft_calloc(sizeof(char *), i);
	asd[i - 1] = NULL;
	i = 0;
	while (arr[i])
	{
		if (i == pos)
		{
			i++;
			continue ;
		}
		else
			asd[j] = ft_strdup(arr[i]);
		j++;
		i++;
	}
	free_dbl(arr);
	return (asd);
}
