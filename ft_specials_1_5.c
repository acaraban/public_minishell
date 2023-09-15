/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials_1_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:48:41 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:02:43 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_specials_1(char *old_txt, t_num *num)
{
	char	*txt;

	txt = ft_strtrim(old_txt, " ");
	ft_free (old_txt);
	if (!txt || ft_strlen(txt) == 0)
	{
		ft_free (txt);
		return (NULL);
	}
	num->vue = (char **)ft_calloc(sizeof(char *), 1);
	num->vue[0] = NULL;
	return (txt);
}

char	*ft_specials_2(char *txt, char *old_txt, t_num *num, t_content *cant)
{
	old_txt = ft_add_varent(txt, num->i, cant[0].global[0].env, cant);
	ft_free (txt);
	txt = ft_strdup(old_txt);
	ft_free (old_txt);
	if (txt == NULL)
	{
		num->ent = 2;
		free_dbl(num->vue);
		ft_free (txt);
		txt = NULL;
		return (NULL);
	}
	return (txt);
}

int	ft_specials_3(char *txt, t_num *num, t_content *cant)
{
	if (err_redsegred(num->vue, cant) || start_end_red(num->vue, cant))
	{
		free_dbl(num->vue);
		ft_free (txt);
		return (0);
	}
	num->vue = start_end_pip(num->vue, cant);
	if (num->vue == NULL)
	{
		ft_free (txt);
		return (0);
	}
	if (txt)
		ft_free (txt);
	num->vue = convert_str_trim(num->vue);
	return (1);
}

int	ft_specials_4(char *txt, t_num *num, t_content *cant)
{
	if (err_red(num->i, txt, cant))
	{
		free_dbl(num->vue);
		ft_free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1 && same_char_across(txt, \
				num->cont, num->i - 1, ' '))
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i + 1);
	num->i++;
	num->cont = num->i + 1;
	return (1);
}

int	ft_specials_5(char *txt, t_num *num, t_content *cant)
{
	if (err_red(num->i, txt, cant))
	{
		free_dbl(num->vue);
		ft_free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1 && same_char_across(txt, \
				num->cont, num->i - 1, ' '))
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i);
	num->cont = num->i + 1;
	return (1);
}
