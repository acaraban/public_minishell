/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:19:02 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/19 18:58:40 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	int	num;

	num = 0;
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
	{
		num = 1;
	}
	return (num);
}

// int main(void)
// {
// 	printf("%d",isalpha(119));
// 	printf("%d",ft_isalpha(119));
// }