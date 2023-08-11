/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:56:26 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/19 18:58:35 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	int	num;

	num = 0;
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0'
			&& a <= '9'))
	{
		num = 1;
	}
	return (num);
}

// int main(void)
// {
// 	printf("%d",isalnum('M'));
// 	printf("%d",ft_isalnum('M'));
// }