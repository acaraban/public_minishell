/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_div_extr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:49:46 by acaraban          #+#    #+#             */
/*   Updated: 2023/09/15 13:35:54 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	mini_all_type_3(t_typered *type, char **final, t_content *cont)
{
	type->i = ft_type_red_salsim(final, type, cont);
	if (type->i < 0)
	{
		ft_free_cont(cont);
		return (0);
	}
	return (1);
}

int	all_type_red(t_typered *type, char **final, t_content *cont)
{
	if (final[type->i][0] == '<' && final[type->i][1] == '<')
	{
		type->ac = ft_type_red_entdbl(final, type, cont);
		if (type->ac == NULL)
		{
			ft_free_cont(cont);
			return (0);
		}
		type->i++;
	}
	else if (final[type->i][0] == '<')
	{
		if (!mini_all_type_1(type, final, cont))
			return (0);
	}
	else if (final[type->i][0] == '>' && final[type->i][1] == '>')
	{
		if (!mini_all_type_2(type, final, cont))
			return (0);
	}
	else if (final[type->i][0] == '>')
		if (!mini_all_type_3(type, final, cont))
			return (0);
	return (1);
}

char	**arg_parsing(char **final, t_content *cont, int *boo)
{
	t_typered	*type;
	char		**ac;

	type = (t_typered *)malloc(sizeof(t_typered) * 1);
	init_typered(type);
	while (final[type->i])
	{
		if (!ft_strchr("<>|", final[type->i][0]))
		{
			if (!arg_parsing_2(final, cont, boo, type))
				return (NULL);
		}
		else if (final[type->i][0] == '|')
			type->h++;
		else
		{
			if (check_type_red(type, final, cont, boo) == 0)
				return (ft_free (type), NULL);
		}
		type->i++;
	}
	ac = type->ac;
	return (ft_free (type), ac);
}

void	ft_final_arg(char **ac, t_content *cont)
{
	if (ac)
	{
		if (!ft_heredoc(ac, cont))
		{
			ft_free_cont(cont);
			free_dbl(ac);
			return ;
		}
		free_dbl(ac);
	}
	ft_executor(cont, cont->global->num_cmd);
	ft_free_cont(cont);
}

int	ft_arg_div(char *txt, t_global *glb)
{
	char		**final;
	t_content	*cont;
	int			tam;
	char		**ac;
	int			boo;

	tam = 1;
	boo = 1;
	txt = init_argdiv_vars(txt);
	if (ft_tam_args(txt, glb) < 0)
		return (1);
	glb->num_cmd = ft_tam_args(txt, glb);
	cont = (t_content *)ft_calloc(sizeof(t_content), glb->num_cmd + 1);
	init_cont_vars(glb, cont);
	final = ft_specials(txt, cont);
	if (final == NULL)
		return (ft_free_cont(cont), 1);
	ac = arg_parsing(final, cont, &boo);
	free_dbl(final);
	if (boo)
		return (ft_final_arg(ac, cont), 1);
	return (1);
}
