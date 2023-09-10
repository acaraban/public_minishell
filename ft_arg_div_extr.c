#include "minishell.h"

int mini_all_type_3(t_typered *type, char **final, t_content *cont)
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
	{
		if (!mini_all_type_3(type, final, cont))
			return (0);
	}
	return (1);
}

char **arg_parsing(char **final, t_content *cont)
{
	t_typered	*type;
	
	type = (t_typered *)malloc(sizeof(t_typered) * 1);
	type->i = 0;
	type->h = 0;
	type->ac = NULL;
	while (final[type->i])
	{
		if (final[type->i][0] != '<' && final[type->i][0] != '>' && final[type->i][0] != '|')
		{
			type->cmd_str = ft_shell_split(final[type->i], ' ', cont);
			if (!cmd_str_cont(cont, type->cmd_str, type->h))
				return (NULL);
		}
		else if (final[type->i][0] == '|')
			type->h++;
		else
			if (!all_type_red(type, final, cont))
				return (NULL);
		type->i++;
	}
	return (type->ac);
}

void	ft_final_arg(char **ac, t_content *cont)
{
	if (ac)
	{
		if (!ft_heredoc(ac, cont))
			return ;
		free_dbl(ac);
	}
	ft_executor(cont);
	ft_free_cont(cont);
}

void	ft_arg_div(char *txt, t_global *glb)
{
	char		**final;
	t_content	*cont;
	int			tam;
	char		**ac;

	tam = 1;
	txt = init_argdiv_vars(txt);
	cont = (t_content *)calloc(sizeof(t_content), tam + 1);
	if (ft_tam_args(txt, glb) < 0)
		return ;
	glb->num_cmd = ft_tam_args(txt, glb);
	free (cont);
	cont = (t_content *)calloc(sizeof(t_content), glb->num_cmd + 1);
	init_cont_vars(glb, cont);
	final = ft_specials(txt, cont, 1);
	if (final == NULL)
		return ;
	ac = arg_parsing(final, cont);
	ft_final_arg(ac, cont);
}