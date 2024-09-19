/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:17:31 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/20 21:56:56 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_sig(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	count;

	(void)context;
	if (sig == SIGUSR1)
	{
		c |= (0x01 << count);
	}
	count++;
	if (count == 8)
	{
		if (c == '\n')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_sig;
	pid = getpid();
	ft_printf("The PID of the current process is: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
