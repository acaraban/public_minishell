/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:49:51 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/14 18:49:55 by msintas-         ###   ########.fr       */
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











