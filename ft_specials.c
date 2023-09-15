/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:32 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:00:13 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_specials_11(char *txt, t_num *num, t_content *cant, char *old_txt)
{
	txt = ft_specials_9(txt, num, cant, old_txt);
	if (num->ent == 2)
		return (NULL);
	if (num->ent == 1)
	{
		if (txt[num->i] == '>' && txt[num->i + 1] == '>')
		{
			if (!ft_specials_4(txt, num, cant))
				return (ft_free (num), NULL);
		}
		else
		{
			if (!ft_specials_10(txt, num, cant))
			{
				ft_free (num);
				return (NULL);
			}
		}
	}
	num->i++;
	return (txt);
}

void	init_specials_vars(t_num *num)
{
	num->i = 0;
	num->cont = 0;
	num->boo = 0;
	num->ent = 0;
}

char	**ft_specials(char *old_txt, t_content *cant)
{
	t_num	*num;
	char	*txt;
	char	**vue;

	num = (t_num *)malloc(sizeof(t_num) * 1);
	init_specials_vars(num);
	num->vue = NULL;
	txt = ft_specials_1(old_txt, num);
	if (txt == NULL)
		return (ft_free(num), NULL);
	while (txt[num->i])
	{
		txt = ft_specials_11(txt, num, cant, old_txt);
		if (!txt)
			return (ft_free(num), NULL);
	}
	if (num->cont < num->i)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i);
	if (!ft_specials_3(txt, num, cant))
		return (ft_free(num), NULL);
	vue = num->vue;
	return (ft_free (num), vue);
}
