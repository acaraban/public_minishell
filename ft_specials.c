#include "minishell.h"

char *ft_specials_11(char *txt, t_num *num, t_content *cant, char *old_txt)
{
	txt = ft_specials_9(txt, num, cant, old_txt);
	if (num->ent == 2)
		return (NULL);
	if (num->ent == 1)
	{
		if (txt[num->i] == '>' && txt[num->i + 1] == '>')
		{
			if (!ft_specials_4(txt, num, cant))
				return(ft_free (num), NULL);
		}
		else
		{
			if(!ft_specials_10(txt, num, cant))
			{
				ft_free (num);
				return (NULL);
			}
		}
	}
	num->i++;
	return (txt);
}

char **ft_specials(char *old_txt, t_content *cant)
{
	t_num *num;
	char *txt;
	char **vue;

	num = (t_num *)malloc(sizeof(t_num) * 1);
	num->i = 0;
	num->cont = 0;
	num->boo = 0;
	num->ent = 0;
	num->vue = NULL;
	txt = ft_specials_1(old_txt, num);
	if (txt == NULL)
		return (NULL);
	while (txt[num->i])
	{
		txt = ft_specials_11(txt, num, cant, old_txt);
		if (!txt)
			return (NULL);
	}
	if (num->cont < num->i)
		num->vue = dobl_prt_free(num->vue, txt, num->cont, num->i);
	if (!ft_specials_3(txt,  num, cant))
		return (NULL);
	vue = num->vue;
	ft_free (num);
	return (vue);
}
