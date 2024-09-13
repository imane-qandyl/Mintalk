/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_digit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:43:32 by imqandyl          #+#    #+#             */
/*   Updated: 2024/08/02 09:37:23 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_digit(unsigned long num)
{
	ssize_t	len;
	int		result;

	len = 0;
	if (num == 0)
	{
		result = ft_characters('0');
		if (result == -1)
			return (-1);
		return (1);
	}
	if (num >= 10)
	{
		len += ft_print_unsigned_digit(num / 10);
		if (len == -1)
			return (-1);
	}
	result = ft_characters(num % 10 + '0');
	if (result == -1)
		return (-1);
	len++;
	return (len);
}
