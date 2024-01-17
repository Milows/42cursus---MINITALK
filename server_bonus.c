/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:17:59 by micabrer          #+#    #+#             */
/*   Updated: 2024/01/17 18:23:22 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID -> %d\n", pid);
	sig.sa_sigaction = signal_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause ();
	}
	return (0);
}
