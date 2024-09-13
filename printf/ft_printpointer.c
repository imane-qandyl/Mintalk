/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:44:04 by imqandyl          #+#    #+#             */
/*   Updated: 2024/08/02 09:56:22 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *ptr)
{
	int	len;
	int	res;

	len = 0;
	if (ptr == NULL)
	{
		res = write(1, "0x0", 3);
		if (res == -1)
			return (-1);
		len += res;
	}
	else
	{
		res = write(1, "0x", 2);
		if (res == -1)
			return (-1);
		len += res;
		res = ft_printhex((unsigned long)ptr, 'x');
		if (res == -1)
			return (-1);
		len += res;
	}
	return (len);
}
