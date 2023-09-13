/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:41:52 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/12 17:35:34 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	custom_pwd(void)
{
	char	*buff;
	size_t	size;

	size = 1024;
	buff = malloc(size);
	if (buff == NULL)
		return ;
	if (getcwd(buff, size) == NULL)
	{
		ft_free (buff);
		perror("getcwd");
		return ;
	}
	else
		printf("%s\n", buff);
	ft_free(buff);
}

/*
	Function to get the pwd as a string
*/

char	*custom_return_pwd(void)
{
	char	*buff;
	size_t	size;

	size = 1024;
	buff = malloc(size);
	if (buff == NULL)
	{
		return (NULL);
	}
	if (getcwd(buff, size) == NULL)
	{
		ft_free (buff);
		perror("getcwd");
		return (NULL);
	}
	return (buff);
}
