#include "minishell.h"

char **ft_specials(char *old_txt, t_content *cant, int errors)
{
	int i;
	int cont;
	int boo;
	char *txt;
	char **vue;

	i = 0;
	cont = 0;
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
			old_txt = ft_add_varent(txt, i, cant[0].global[0].env, cant);
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
			if (err_red(i, txt, cant))
				return (NULL);
			if (i > 1 && cont < i - 1)
				vue = dobl_prt_free(vue, txt, cont, i - 1);
			vue = dobl_prt_free(vue, txt, i, i + 1);
			i++;
			cont = i + 1;
		}
		else if (txt[i] == '>')
		{
			if (err_sim_red(txt, i, cant))
				return (NULL);
			if (i > 1 && cont < i - 1)
				vue = dobl_prt_free(vue, txt, cont, i - 1);
			vue = dobl_prt_free(vue, txt, i, i);
			cont = i + 1;
		}
		else if (txt[i] == '<' && txt[i + 1] == '<')
		{
			if (err_red(i, txt, cant))
				return (NULL);
			if (i > 1 && cont < i - 1)
				vue = dobl_prt_free(vue, txt, cont, i - 1);
			vue = dobl_prt_free(vue, txt, i, i + 1);
			i++;
			cont = i + 1;
		}
		else if (txt[i] == '<')
		{
			if (i > 1 && cont < i - 1)
				vue = dobl_prt_free(vue, txt, cont, i - 1);
			vue = dobl_prt_free(vue, txt, i, i);
			cont = i + 1;
		}
		else if (txt[i] == '|')
		{
			if (err_dobpip(txt, i, cant))
				return (NULL);
			if (i > 1 && cont < i - 1)
				vue = dobl_prt_free(vue, txt, cont, i - 1);
			vue = dobl_prt_free(vue, txt, i, i);
			cont = i + 1;
		}
		i++;
	}
	if (cont < i)
		vue = dobl_prt_free(vue, txt, cont, i);
	if (err_redsegred(vue, cant) || start_end_red(vue, cant))
	{
		return (NULL);
	}
	if (errors)
	{
		vue = start_end_pip(vue, cant);
		if (vue == NULL)
			return (NULL);
	}
	free (txt);
	return (vue);
}