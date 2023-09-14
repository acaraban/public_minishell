/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:35:37 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/14 18:31:42 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include <stdio.h>
//#include <string.h>

/*
    Function that checks if a char is the same in every position between two
    indexes.
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
        while(i < pos_ini) // mientras que el indice sea menor que la posicion inicial, avanza
        {
            i++;
        }
        while(i <= pos_fin && count < diff ) // mientras que no llegue a la posicion final, recorro el string
        {
            //printf("%c\n", str[i]);
            while(str[i] == c)
            {
                //printf("encontre el char: %c\n", c);
                count++;
                i++;
            }
            i++;
        }
        //printf("count %d\n", count);
        if (count == diff)
        {
            //printf("return 0");
            return (0);
        }
        i++;
    }
    //printf("return 1");
    return (1);
}



/*int main(void)
{
    char *str;

    str = "m$$$$$$$ es esta";
    same_char_across(str, 1, 7, '$');
    
     
    return (0);
}*/











