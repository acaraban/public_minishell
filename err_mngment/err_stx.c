/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_stx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:50:07 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 12:50:08 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	err_stx(char *txt, t_content *cont)
{
	ft_printf("%s", txt);
	cont->global->err_stat = STX_ERR;
}
