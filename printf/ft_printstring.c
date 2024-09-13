/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:44:08 by imqandyl          #+#    #+#             */
/*   Updated: 2024/08/02 14:45:35 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(char *str)
{
	int	count;
	int	res;

	count = 0;
	if (str == NULL)
	{
		res = write(1, "(null)", 6);
		if (res == -1)
			return (-1);
		return (6);
	}
	while (str[count])
	{
		res = ft_characters(str[count]);
		if (res == -1)
			return (-1);
		count++;
	}
	return (count);
}
