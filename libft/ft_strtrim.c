/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:02:25 by isam-alv          #+#    #+#             */
/*   Updated: 2025/05/19 19:58:39 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begg;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	begg = 0;
	while (s1[begg] && ft_strchr(set, s1[begg]))
		begg++;
	if (s1[begg] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end > begg && ft_strchr(set, s1[end]))
		end--;
	result = ft_substr(s1, begg, (end - begg + 1));
	return (result);
}
