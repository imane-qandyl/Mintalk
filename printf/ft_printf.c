/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:56:52 by imqandyl          #+#    #+#             */
/*   Updated: 2024/08/02 15:07:40 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatspecifier(va_list list, char c)
{
	if (c == 'c')
		return (ft_characters(va_arg(list, int)));
	else if (c == 's')
		return (ft_printstring(va_arg(list, char *)));
	else if (c == 'p')
		return (ft_printpointer(va_arg(list, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printdigit(va_arg(list, int)));
	else if (c == 'u')
		return (ft_print_unsigned_digit(va_arg(list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(list, unsigned int), c));
	else if (c == '%')
		return (ft_characters('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	ssize_t	result;

	i = -1;
	result = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i] || !ft_strchr("udixXcsp%", str[i]))
				result += ft_characters(str[i]);
			result += ft_formatspecifier(ap, str[i]);
		}
		else
		{
			result += ft_characters(str[i]);
		}
		if (result == -1)
			return (-1);
	}
	va_end(ap);
	return (result);
}
