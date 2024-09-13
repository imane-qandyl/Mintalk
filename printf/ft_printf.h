/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:43:56 by imqandyl          #+#    #+#             */
/*   Updated: 2024/08/02 13:19:30 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h> 

int		ft_characters(int c);
int		ft_print_unsigned_digit(unsigned long num);
int		ft_printdigit(long num);
int		ft_printhex(unsigned long num, char hex_case);
int		ft_printpointer(void *ptr);
int		ft_printstring(char *str);
int		ft_printf(const char *str, ...);
char	*ft_strchr(const char *s, int c);

#endif