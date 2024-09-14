/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imqandyl <imqandyl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:20:31 by imqandyl          #+#    #+#             */
/*   Updated: 2024/09/14 15:22:12 by imqandyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (!*str)
		ft_printf("Error: empty string");
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ft_printf("Error: Invalid characters in PID\n");
	return (result * sign);
}

void	ft_atob(int pid, char c)
{
	int		bit;
	int		pid_check;

	if (pid <= 0)
	{
		ft_printf("Error: Invalid PID\n");
		return ;
	}
	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			pid_check = kill(pid, SIGUSR1);
		else
			pid_check = kill(pid, SIGUSR2);
		if (pid_check == -1)
		{
			ft_printf("Error: Signal transmission failed\n");
			return ;
		}
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0 || !argv[2][0])
		{
			ft_printf("Error: Invalid PID or empty message string");
			return (1);
		}
		while (argv[2][i] != '\0')
		{
			ft_atob(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
