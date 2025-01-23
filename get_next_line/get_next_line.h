/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:03:08 by hyalcink          #+#    #+#             */
/*   Updated: 2024/05/15 17:40:22 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_end_ofline(char *buffer);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(const char *str);
char	*ft_next_line(char *str);
char	*ft_read_line(int fd, char *str);
char	*ft_new_line(char *str);

#endif
