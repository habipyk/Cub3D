/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyalcink <hyalcink@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:12:59 by hyalcink          #+#    #+#             */
/*   Updated: 2022/12/24 00:13:09 by hyalcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;
	size_t	req;

	req = count * size;
	rtn = malloc(req);
	if (!rtn)
		return (0);
	ft_memset(rtn, 0, req);
	return (rtn);
}
