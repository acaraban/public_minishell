/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:25:35 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/20 20:13:51 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned long int				pos;
	unsigned char					*ptr;

	pos = 0;
	ptr = (unsigned char *)s;
	while (pos < n)
	{
		ptr[pos] = '\0';
		pos++;
	}
	return (s);
}

// int main(void)
// {
// 	char h[] = "jgaasslfda";
// 	bzero(h, 3);
// 	printf("%s", h);
// 	char j[] = "asdfadfhoasiufh";
// 	ft_bzero(j, 3);
// 	printf("%s", j);
// }