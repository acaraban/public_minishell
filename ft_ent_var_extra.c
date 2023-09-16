/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ent_var_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:01:34 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/16 16:01:43 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_varent(t_addvarent *varent, char *txt, int pos)
{
	ft_free (varent->aux);
	varent->aux = ft_substr(txt, pos + varent->i, ft_strlen(txt) - pos - 1);
	ft_free (varent->aux2);
	varent->aux2 = ft_strjoin(varent->add, varent->aux);
}