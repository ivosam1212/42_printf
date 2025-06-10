/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:03:26 by isam-alv          #+#    #+#             */
/*   Updated: 2025/05/16 14:55:34 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char	*psrc;
	unsigned char	*pdst;
	size_t			i;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && psrc[i] != '\0')
		{
			pdst[i] = psrc[i];
			i++;
		}
		pdst[i] = '\0';
	}
	return (ft_strlen((char *)psrc));
}
