#include "minishell.h"

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
	ft_dbl_printf("vue: \n-", num->vue, "-\n", 0);
	return (num->vue);
}
