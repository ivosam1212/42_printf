/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 21:12:17 by isam-alv          #+#    #+#             */
/*   Updated: 2025/05/14 21:33:58 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	dst_size = 0;
	while (dst[dst_size] && dst_size < size)
		dst_size++;
	if (dst_size >= size)
		return (size + src_size);
	i = 0;
	while (src[i] && (dst_size + i + 1) < size)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}
