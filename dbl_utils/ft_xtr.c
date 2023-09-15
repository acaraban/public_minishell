/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:07:43 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/15 12:08:45 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**alloc_when_null(char **jj, int inicial, int conta)
{
	jj = (char **)ft_calloc(sizeof(char *), 2);
	jj[0] = (char *)ft_calloc(sizeof(char ), conta - inicial + 2);
	jj[1] = NULL;
	return (jj);
}

void	alloc_and_copy(t_xtr *xtr, int inicial, int conta, char **arr)
{
	xtr->jj[xtr->i] = (char *)ft_calloc(sizeof(char ), conta - inicial + 2);
	xtr->jj[xtr->i + 1] = NULL;
	while (xtr->h < xtr->i)
	{
		xtr->jj[xtr->h] = ft_strdup(arr[xtr->h]);
		xtr->h++;
	}
}

void	copy_array(int inicial, int conta, t_xtr *xtr, char *txt)
{
	int	h;

	h = 0;
	while (h + inicial < conta + 1)
	{
		xtr->jj[xtr->i][h] = txt[h + inicial];
		h++;
	}
}

char	**dobl_prt_free(char **arr, char *txt, int inicial, int conta)
{
	t_xtr	xtr;

	xtr.i = 0;
	xtr.h = 0;
	xtr.jj = NULL;
	if (arr[0] == NULL)
		xtr.jj = alloc_when_null(xtr.jj, inicial, conta);
	else
	{
		while (arr[xtr.i])
			xtr.i++;
		xtr.jj = (char **)ft_calloc(sizeof(char *), xtr.i + 2);
		alloc_and_copy(&xtr, inicial, conta, arr);
	}
	copy_array(inicial, conta, &xtr, txt);
	xtr.h = 0;
	if (arr[0] != NULL)
	{
		while (xtr.h < xtr.i + 1)
			ft_free (arr[xtr.h++]);
	}
	ft_free (arr);
	return (xtr.jj);
}
