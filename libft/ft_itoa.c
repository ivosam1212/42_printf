/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:50:50 by isam-alv          #+#    #+#             */
/*   Updated: 2025/05/27 14:50:56 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_fillstr(char *str, int len, int sign, int n)
{
	int	i;

	str[len + sign] = '\0';
	i = len + sign - 1;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		is_neg;
	char	*result;
	int		s_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
	if (n == 0)
		return (ft_strdup("0"));
	s_len = ft_intlen(n);
	result = (char *)malloc((s_len + is_neg + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	return (ft_fillstr(result, s_len, is_neg, n));
}
