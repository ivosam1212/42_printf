/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:57:09 by isam-alv          #+#    #+#             */
/*   Updated: 2025/06/18 17:14:18 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(long long int val, int base)
{
	int				size;
	long long int	n;

	size = 0;
	n = val;
	if (val == 0)
		return (1);
	if (val < 0 && base == 10)
	{
		n = -n;
		size++;
	}
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(long long int val, int base)
{
	char				*str;
	long long int		n;
	int					size;

	if (val == 0)
		return (ft_strdup("0"));
	size = ft_num_len(val, base);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	n = val;
	if (val < 0 && base == 10)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n)
	{
		str[--size] = n % base + '0';
		n /= base;
	}
	return (str);
}

int	ft_print_dig(long n, int base)
{
	int		print_length;
	char	*num;

	print_length = 0;
	num = ft_itoa_base(n, base);
	print_length = ft_print_str(num);
	free(num);
	return (print_length);
}
