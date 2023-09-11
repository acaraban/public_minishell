#include "minishell.h"

typedef struct s_num
{
	int i;
	int cont;
	int boo;
	char **vue;
	int ent;
} t_num;

char *ft_specials_1(char *old_txt, t_num *num)
{
	char *txt;

	txt = ft_strtrim(old_txt, " ");
	free (old_txt);
	if (!txt || ft_strlen(txt) == 0)
	{
		free (txt);
		return (NULL);
	}
	num->vue = (char **)calloc(sizeof(char *), 1);
	num->vue[0] = NULL;
	return (txt);
}

int	ft_specials_2(char *txt, char *old_txt, t_num *num, t_content *cant)
{
	old_txt = ft_add_varent(txt, num->i, cant[0].global[0].env, cant);
	free (txt);
	txt = strdup(old_txt);
	free (old_txt);
	if (txt == NULL)
	{
		free_dbl(num->vue);
		free (txt);
		return (0);
	}
	return (1);
}

int	ft_specials_3(char *txt, t_num *num, t_content *cant)
{
	if (err_redsegred(num->vue, cant) || start_end_red(num->vue, cant))
	{
		free (txt);
		return (0);
	}
	num->vue = start_end_pip(num->vue, cant);
	if (num->vue == NULL)
	{
		free (txt);
		return (0);
	}
	free (txt);
	num->vue = convert_str_trim(num->vue);
	return (1);
}

int	ft_specials_4(char *txt, t_num *num, t_content *cant)
{
	if (err_red(num->i, txt, cant))
	{
		free_dbl(num->vue);
		free (txt);
		return (0);
	}
	ft_printf("aqui si llega\n");
	if (num->i > 1 && same_char_across(txt, num->cont, num->i - 1, ' '))
	{
		ft_printf("aqui entra\n");
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	}
		
	ft_printf("aqui no llega\n");
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
		free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i + 1);
	num->i++;
	num->cont = num->i + 1;
	return (1);
}

int	ft_specials_6(char *txt, t_num *num, t_content *cant)
{
	if (err_sim_red(txt, num->i, cant))
	{
		free_dbl(num->vue);
		free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i);
	num->cont = num->i + 1;
	return (1);
}

int	ft_specials_7(char *txt, t_num *num, t_content *cant)
{
	if (err_red(num->i, txt, cant))
	{
		free_dbl(num->vue);
		free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i + 1);
	num->i++;
	num->cont = num->i + 1;
	return (1);
}

void	ft_specials_8(char *txt, t_num *num)
{
	if (num->i > 1 && num->cont < num->i - 1)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i);
	num->cont = num->i + 1;
}

int	ft_specials_9(char *txt, t_num *num, t_content *cant, char *old_txt)
{
	if ((num->boo == 1 || num->boo == 0) && txt[num->i] == '$')
	{
		if (!ft_specials_2(txt, old_txt, num, cant))
			return (2);
	}
	else if (num->boo == 1 && (txt[num->i] == '\"'))
		num->boo = 0;
	else if(num->boo == 2 && (txt[num->i] == '\''))
		num->boo = 0;
	else if (num->boo && (txt[num->i] == '\"'))
		num->boo = 1;
	else if (num->boo && (txt[num->i] == '\''))
		num->boo = 2;
	else if(num->boo)
		num->boo = num->boo + 1 - 1;
	else
		return (0);
	return (1);
}

int	ft_specials_10(char *txt, t_num *num, t_content *cant)
{
	if (txt[num->i] == '>')
	{
		if (!ft_specials_6(txt, num, cant))
			return (0);
	}
	else if (txt[num->i] == '<' && txt[num->i + 1] == '<')
	{
		if (!ft_specials_7(txt, num, cant))
			return (0);
	}
	else if (txt[num->i] == '<')
		ft_specials_8(txt, num);
	else if (txt[num->i] == '|')
	{
		if (!ft_specials_5(txt, num, cant))
			return (0);
	}
	return (1);
}

int	ft_specials_11(char *txt, t_num *num, t_content *cant, char *old_txt)
{
	num->ent = ft_specials_9(txt, num, cant, old_txt);
	if (num->ent == 2)
		return (0);
	if (txt[num->i] == '>' && txt[num->i + 1] == '>' && !num->ent)
	{
		if (!ft_specials_4(txt, num, cant))
			return(0);
	}
	else
	{
		if(!ft_specials_10(txt, num, cant))
			return (0);
	}
	num->i++;
	return (1);
}

char **ft_specials(char *old_txt, t_content *cant)
{
	t_num *num;
	char *txt;

	num = (t_num *)malloc(sizeof(t_num) * 1);
	num->i = 0;
	num->cont = 0;
	num->boo = 0;
	num->ent = 0;
	txt = ft_specials_1(old_txt, num);
	if (txt == NULL)
		return (NULL);
	while (txt[num->i])
	{
		if(!ft_specials_11(txt, num, cant, old_txt))
			return (NULL);
	}
	if (num->cont < num->i)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i);
	if (!ft_specials_3(txt,  num, cant))
		return (NULL);
	//ft_dbl_printf("vue: \n-", num->vue, "-\n", 0);
	return (num->vue);
}
