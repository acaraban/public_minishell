/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:35:37 by msintas-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/14 18:33:52 by msintas-         ###   ########.fr       */
=======
/*   Updated: 2023/09/14 18:31:42 by acaraban         ###   ########.fr       */
>>>>>>> 03e290eb9a919b433ec436c5f6613683297a3feb
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
    Function that checks if a char is the same in every position between two
    indexes. It starts at ini position and checks until final position.
    If it is, returns 0.
    It not, returns 1.
*/

int same_char_across(char *str, int pos_ini, int pos_fin, char c)
{
    int i;
    int diff;
    int count;

    i = 0;
    count = 0;
    diff = (pos_fin - pos_ini) + 1;
    while((i <= pos_fin) && str[i])
    {
        while(i < pos_ini)
            i++;
        while(i <= pos_fin && count < diff )
        {
            while(str[i] == c)
            {
                count++;
                i++;
            }
            i++;
        }
        if (count == diff)
            return (0);
        i++;
    }
    return (1);
}



/*int main(void)
{
    char *str;

    str = "m$$$$$$$ es esta";
    same_char_across(str, 1, 7, '$');
    
     
    return (0);
}*/











