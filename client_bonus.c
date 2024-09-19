/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:17:23 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/22 14:16:27 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int signal)
{
	(void)signal;
	ft_printf("Message Received");
	exit(1);
}

static void	ft_send_msg(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		bit++;
		usleep(350);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		i = 0;
		pid = mt_atoi(av[1]);
		if (pid == -1 || pid == 0)
		{
			return (1);
		}
		signal(SIGUSR1, ft_confirm);
		while (av[2][i])
		{
			ft_send_msg(pid, av[2][i]);
			i++;
		}
		ft_send_msg(pid, '\n');
		pause();
	}
	else
		return (0);
}
