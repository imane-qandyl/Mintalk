/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:44:00 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/13 17:44:25 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, char hex_case)
{
	char	c;
	int		result;

	if (num > 15)
		return (0);
	if (num < 10)
		c = num + '0';
	else
	{
		if (hex_case == 'x')
			c = num - 10 + 'a';
		else
			c = num - 10 + 'A';
	}
	result = ft_characters(c);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_printhex(unsigned long num, char hex_case)
{
	int	len;
	int	result;

	len = 0;
	if (num >= 16)
	{
		len += ft_printhex(num / 16, hex_case);
		if (len == -1)
			return (-1);
	}
	result = ft_hex(num % 16, hex_case);
	if (result == -1)
		return (-1);
	len += result;
	return (len);
}
