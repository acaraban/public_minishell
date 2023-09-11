/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_div_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:01 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/11 17:47:13 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_typered(t_typered *type)
{
    type->i = 0;
	type->h = 0;
	type->ac = NULL;
}

int check_type_red(t_typered *type, char **final, t_content *cont, int *boo)
{
    if (!all_type_red(type, final, cont))
    {
        *boo = 0;
        return (0);
    }
    return (1);
}