/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:47:10 by acaraban          #+#    #+#             */
/*   Updated: 2022/06/20 20:18:39 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int v, size_t n)
{
	unsigned long int				pos;
	unsigned char					*ptr;

	pos = 0;
	ptr = (unsigned char *)s;
	while (pos < n)
	{
		ptr[pos] = (unsigned char)v;
		pos++;
	}
	return (s);
}

// int main( void )
// {
//  char buffer[] = "This is a test of the memset function";
//  printf( "Before: %s\n", buffer );
//  memset( buffer, '*', 4 );
//  printf( "After: %s\n", buffer );

//  char sf[] = "This is a test of the memset function";
//  printf( "Before: %s\n", sf );
//  ft_memset( sf, '*', 4 );
//  printf( "After: %s\n", sf );
//  }