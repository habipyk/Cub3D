/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:02:52 by hyalcink          #+#    #+#             */
/*   Updated: 2024/05/15 17:40:22 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *str, char	*buffer)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	result = malloc(sizeof(char) * ft_strlen1(str) + ft_strlen1(buffer) + 1);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	while (buffer[j])
		result[i++] = buffer[j++];
	free(str);
	result[i] = '\0';
	return (result);
}

char	*ft_new_line(char *str)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	buffer = malloc(sizeof(char) * (ft_strlen1(str) - i + 1));
	i++;
	if (!buffer)
		return (0);
	j = 0;
	while (str[i])
		buffer[j++] = str[i++];
	buffer[j] = '\0';
	free(str);
	return (buffer);
}

char	*ft_next_line(char *str)
{
	char	*line;
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	if (!str || !str[i])
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	line = malloc(sizeof(char *) * (i + 2));
	if (!line)
		return (0);
	a = i;
	j = 0;
	i = 0;
	while (str[i] && i <= a - 1)
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}
