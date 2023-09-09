/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msintas- <msintas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:41:52 by msintas-          #+#    #+#             */
/*   Updated: 2023/09/09 20:18:13 by msintas-         ###   ########.fr       */
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
		free (buff);
		perror("getcwd");
		return ;
	}
	else
		printf("%s\n", buff);
	free(buff);
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
		free (buff);
		perror("getcwd");
		return (NULL);
	}
	return (buff);
}
