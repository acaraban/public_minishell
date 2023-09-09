#include "minishell.h"

char **ft_specials(char *old_txt, t_content *cont, int errors)
{
	int i;
	int count;
	int boo;
	char *txt;
	char **vue;

	i = 0;
	count = 0;
	boo = 0;
	txt = ft_strtrim(old_txt, " ");
	free (old_txt);
	if (!txt || ft_strlen(txt) == 0)
		return (NULL);
	vue = (char **)calloc(sizeof(char *), 1);
	vue[0] = NULL;
	while (txt[i])
	{
		if ((boo == 1 || boo == 0) && txt[i] == '$')
		{
			old_txt = ft_add_varent(txt, i, cont[0].global[0].env, cont);
			free (txt);
			txt = strdup(old_txt);
			free (old_txt);
			if (txt == NULL)
				return (NULL);
		}
		else if (boo == 1 && (txt[i] == '\"'))
			boo = 0;
		else if (boo == 2 && (txt[i] == '\''))
			boo = 0;
		else if (!boo && (txt[i] == '\"'))
			boo = 1;
		else if (!boo && (txt[i] == '\''))
			boo = 2;
		else if (boo)
			boo = boo + 1 - 1;
		else if (txt[i] == '>' && txt[i + 1] == '>')
		{
			if (err_red(i, txt, cont))
				return (NULL);
			if (i > 1 && count < i - 1)
				vue = dobl_prt_free(vue, txt, count, i - 1);
			vue = dobl_prt_free(vue, txt, i, i + 1);
			i++;
			count = i + 1;
		}
		else if (txt[i] == '>')
		{
			if (err_sim_red(txt, i, cont))
				return (NULL);
			if (i > 1 && count < i - 1)
				vue = dobl_prt_free(vue, txt, count, i - 1);
			vue = dobl_prt_free(vue, txt, i, i);
			count = i + 1;
		}
		else if (txt[i] == '<' && txt[i + 1] == '<')
		{
			if (err_red(i, txt, cont))
				return (NULL);
			if (i > 1 && count < i - 1)
				vue = dobl_prt_free(vue, txt, count, i - 1);
			vue = dobl_prt_free(vue, txt, i, i + 1);
			i++;
			count = i + 1;
		}
		else if (txt[i] == '<')
		{
			if (i > 1 && count < i - 1)
				vue = dobl_prt_free(vue, txt, count, i - 1);
			vue = dobl_prt_free(vue, txt, i, i);
			count = i + 1;
		}
		else if (txt[i] == '|')
		{
			if (err_dobpip(txt, i, cont))
				return (NULL);
			if (i > 1 && count < i - 1)
				vue = dobl_prt_free(vue, txt, count, i - 1);
			vue = dobl_prt_free(vue, txt, i, i);
			count = i + 1;
		}
		i++;
	}
	if (count < i)
		vue = dobl_prt_free(vue, txt, count, i);
	if (err_redsegred(vue, cont) || start_end_red(vue, cont))
	{
		return (NULL);
	}
	if (errors)
	{
		vue = start_end_pip(vue, cont);
		if (vue == NULL)
			return (NULL);
	}
	//ft_dbl_printf("este es vue: \n", vue, "\n", 0);
	return (vue);
}