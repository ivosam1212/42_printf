/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isam-alv <isam-alv@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:14:12 by isam-alv          #+#    #+#             */
/*   Updated: 2025/06/18 16:39:16 by isam-alv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6); 
	}
	i = 0; 
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
