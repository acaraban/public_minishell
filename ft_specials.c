#include "minishell.h"

char **ft_specials(char *old_txt, t_content *cont, int errors)
{
	t_specials special;

	//special = ft_calloc(sizeof(t_specials), 1);
	special.i = 0;
	special.count = 0;
	special.boo = 0;
	special.txt = ft_strtrim(old_txt, " ");
	
	free (old_txt);
	if (!special.txt || ft_strlen(special.txt) == 0)
		return (NULL);
	special.vue = (char **)calloc(sizeof(char *), 1);
	special.vue[0] = NULL;
	while (special.txt[special.i])
	{
		if ((special.boo == 1 || special.boo == 0) && special.txt[special.i] == '$')
		{
			old_txt = ft_add_varent(special.txt, special.i, cont[0].global[0].env, cont);
			free (special.txt);
			special.txt = strdup(old_txt);
			free (old_txt);
			if (special.txt == NULL)
				return (NULL);
		}
		else if (special.boo == 1 && (special.txt[special.i] == '\"'))
			special.boo = 0;
		else if (special.boo == 2 && (special.txt[special.i] == '\''))
			special.boo = 0;
		else if (!special.boo && (special.txt[special.i] == '\"'))
			special.boo = 1;
		else if (!special.boo && (special.txt[special.i] == '\''))
			special.boo = 2;
		else if (special.boo)
			special.boo = special.boo + 1 - 1;
		else if (special.txt[special.i] == '>' && special.txt[special.i + 1] == '>')
		{
			if (err_red(special.i, special.txt, cont))
				return (NULL);
			if (special.i > 1 && special.count < special.i - 1)
				special.vue = dobl_prt_free(special.vue, special.txt, special.count, special.i - 1);
			special.vue = dobl_prt_free(special.vue, special.txt, special.i, special.i + 1);
			special.i++;
			special.count = special.i + 1;
		}
		else if (special.txt[special.i] == '>')
		{
			if (err_sim_red(special.txt, special.i, cont))
				return (NULL);
			if (special.i > 1 && special.count < special.i - 1)
				special.vue = dobl_prt_free(special.vue, special.txt, special.count, special.i - 1);
			special.vue = dobl_prt_free(special.vue, special.txt, special.i, special.i);
			special.count = special.i + 1;
		}
		else if (special.txt[special.i] == '<' && special.txt[special.i + 1] == '<')
		{
			if (err_red(special.i, special.txt, cont))
				return (NULL);
			if (special.i > 1 && special.count < special.i - 1)
				special.vue = dobl_prt_free(special.vue, special.txt, special.count, special.i - 1);
			special.vue = dobl_prt_free(special.vue, special.txt, special.i, special.i + 1);
			special.i++;
			special.count = special.i + 1;
		}
		else if (special.txt[special.i] == '<')
		{
			if (special.i > 1 && special.count < special.i - 1)
				special.vue = dobl_prt_free(special.vue, special.txt, special.count, special.i - 1);
			special.vue = dobl_prt_free(special.vue, special.txt, special.i, special.i);
			special.count = special.i + 1;
		}
		else if (special.txt[special.i] == '|')
		{
			if (err_dobpip(special.txt, special.i, cont))
				return (NULL);
			if (special.i > 1 && special.count < special.i - 1)
				special.vue = dobl_prt_free(special.vue, special.txt, special.count, special.i - 1);
			special.vue = dobl_prt_free(special.vue, special.txt, special.i, special.i);
			special.count = special.i + 1;
		}
		special.i++;
	}
	if (special.count < special.i)
		special.vue = dobl_prt_free(special.vue, special.txt, special.count, special.i);
	if (err_redsegred(special.vue, cont) || start_end_red(special.vue, cont))
	{
		return (NULL);
	}
	if (errors)
	{
		special.vue = start_end_pip(special.vue, cont);
		if (special.vue == NULL)
			return (NULL);
	}
	//ft_dbl_printf("este es special.vue: \n", special.vue, "\n", 0);
	return (special.vue);
}