/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:27:47 by acaraban          #+#    #+#             */
/*   Updated: 2023/02/03 18:10:16 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 10

char	*newwhile(char *nuevo, char *stc, size_t pos, size_t len);
char	*newstc(char *stc, int tam);
char	*newbuff(char *stc);
char	*get_next_line(int fd);
void	*ft_bzero_2(void *s, size_t n);
void	*ft_calloc_2(size_t number, size_t size);
size_t	ft_strlen_2(char *s);
size_t	ft_strlensalt(const char *str);
char	*ft_strjoin_m(char *left_str, char *buff, int rd);

#endif