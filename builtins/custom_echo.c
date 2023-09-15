/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:10:37 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/14 20:54:40 by msintas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// desde donde se imprime, el 2
//ft_printf("%s", cont[i].full_comand[2]);

void	custom_echo(t_content *cont, int i)
{
	int n;
	int total;

	n = 0;
	while(cont[i].full_comand[n]) // solo para contar cuantos args me estan pasando
	{
		printf("cont[i].full_comand[%d]: %s\n", n, cont[i].full_comand[n]);
		n++;
	}
	total = n;
	n = 2; // pongo el index desde donde quiero imprimir
	printf("total args = %d\n", n);
	if (cont[i].full_comand[2] == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		while(cont[i].full_comand[n])
		{
			
			//printf("cont[i].full_comand[%d]: %s\n", n, cont[i].full_comand[n]);
			/*printf("start:\n");
			printf("n = %d\n", n);
			printf("total: %d\n", total);*/
			ft_printf("%s", cont[i].full_comand[n]);
			if (n < total)
			{
				// imprime espacio
				//printf("dentro");
				printf(" ");
			}
			n++;
		}
		
	}
}
