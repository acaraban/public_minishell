/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:45:37 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/19 18:59:49 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	int	num;

	num = 0;
	if ((a >= '0' && a <= '9'))
	{
		num = 1;
	}
	return (num);
}

// int main(void)
// {
// 	printf("%d",isdigit(46));
// 	printf("%d",ft_isdigit(46));
// }