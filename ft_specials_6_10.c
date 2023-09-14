#include "minishell.h"

int	ft_specials_6(char *txt, t_num *num, t_content *cant)
{
	if (err_sim_red(txt, num->i, cant))
	{
		free_dbl(num->vue);
		ft_free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1 && same_char_across(txt, num->cont, num->i - 1, ' '))
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
		ft_free (txt);
		return (0);
	}
	if (num->i > 1 && num->cont < num->i - 1 && same_char_across(txt, num->cont, num->i - 1, ' '))
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i + 1);
	num->i++;
	num->cont = num->i + 1;
	return (1);
}

void	ft_specials_8(char *txt, t_num *num)
{
	if (num->i > 1 && num->cont < num->i - 1 && same_char_across(txt, num->cont, num->i - 1, ' '))
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i - 1);
	num->vue = dobl_prt_free(num->vue, txt, num->i, num->i);
	num->cont = num->i + 1;
}

char *ft_specials_9(char *txt, t_num *num, t_content *cant, char *old_txt)
{
	if ((num->boo == 1 || num->boo == 0) && txt[num->i] == '$')
	{
		txt = ft_specials_2(txt, old_txt, num, cant);
		if (txt == NULL)
		{
			num->ent = 2;
			return (NULL);
		}
	}
	else if (num->boo == 1 && (txt[num->i] == '\"'))
	{
		num->ent = 0;
		num->boo = 0;
		return (txt);
	}
	else if(num->boo == 2 && (txt[num->i] == '\''))
	{
		num->ent = 0;
		num->boo = 0;
		return (txt);
	}
	else if (!num->boo && (txt[num->i] == '\"'))
	{
		num->ent = 0;
		num->boo = 1;
		return (txt);
	}
	else if (!num->boo && (txt[num->i] == '\''))
	{
		num->ent = 0;
		num->boo = 2;
		return (txt);
	}
	else if(num->boo)
	{
		num->ent = 0;
		num->boo = num->boo + 1 - 1;
		return (txt);
	}
	num->ent = 1;
	return (txt);
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

