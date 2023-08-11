/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaraban <acaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:27:47 by acaraban          #+#    #+#             */
/*   Updated: 2023/02/03 18:10:16 by acaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*newwhile(char *new, char *stc, size_t pos, size_t len);
char	*newstc(char *stc, int tam);
char	*newbuff(char *stc);
char	*get_next_line(int fd);
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc_2(size_t number, size_t size);
size_t	ft_strlen(char *s);
size_t	ft_strlensalt(const char *str);
char	*ft_strjoin(char *left_str, char *buff, int rd);

#endif