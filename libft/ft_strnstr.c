/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:10:14 by hyalcink          #+#    #+#             */
/*   Updated: 2022/12/24 00:10:35 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = -1;
	while (++i < len && *(haystack + i))
	{
		j = -1;
		while ((i + ++j) < len && *(haystack + i + j) == *(needle + j))
			if (!*(needle + j + 1))
				return ((char *)(haystack + i));
	}
	return (NULL);
}
