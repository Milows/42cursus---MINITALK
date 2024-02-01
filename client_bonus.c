/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:17:57 by micabrer          #+#    #+#             */
/*   Updated: 2024/01/18 17:11:41 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	confirm_signal(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("signal received\n");
}

void	send_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi((char *)argv[1]);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR2, confirm_signal);
			send_bits(pid, (char)argv[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Try: ./client [PID] [\"MESSAGE\"]\n");
		return (1);
	}
	return (0);
}
