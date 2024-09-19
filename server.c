/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:12:06 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/20 21:56:24 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_sig(int sig)
{
	static char	c;
	static int	count;

	if (sig == SIGUSR1)
	{
		c |= (0x01 << count);
	}
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("The PID of the current process is: %d\n", pid);
	signal(SIGUSR1, receive_sig);
	signal(SIGUSR2, receive_sig);
	while (1)
	{
		pause();
	}
	return (0);
}
