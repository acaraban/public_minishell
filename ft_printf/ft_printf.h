/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:20:21 by acaraban          #+#    #+#             */
/*   Updated: 2023/02/02 20:28:31 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>	

char			*ft_itoa(int n);
size_t			ft_strlen_3(const char *str);
int				ft_printf(char const *str, ...);
int				print_int(int j);
int				print_ent(int j);
int				print_dec(unsigned int j);
void			hex(unsigned int num, int *tam);
void			hexup(unsigned int num, int *tam);
void			putptr(unsigned long long num);
int				print_string(char *str);
int				printchar(int j);
int				ptrr(unsigned long long num, int h);
int				limptr(int n, int h);

#endif
