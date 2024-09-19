/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:23:52 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/21 20:50:36 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr_len(unsigned int n, int fd)
{
	int	len;
	int	temp;

	len = 0;
	if (n >= 10)
	{
		temp = ft_putnbr_len(n / 10, fd);
		if (temp == -1)
			return (-1);
		len += temp;
		temp = ft_putchar_len(n % 10 + '0', fd);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	else
	{
		temp = ft_putchar_len(n + '0', fd);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	return (len);
}
