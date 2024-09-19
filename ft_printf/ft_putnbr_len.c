/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:08:36 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/22 14:40:52 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	writenum(int len, int n, int fd)
{
	int	temp;

	temp = len;
	if (n == -2147483648)
		len += ft_putstr_len("-2147483648", fd);
	else if (n < 0)
	{
		temp = ft_putchar_len('-', fd);
		if (temp == -1)
			return (-1);
		len += temp;
		len += ft_putnbr_len(-n, fd);
	}
	else if (n >= 10)
	{
		temp = ft_putnbr_len(n / 10, fd);
		if (temp == -1)
			return (-1);
		len += temp;
		len += ft_putchar_len(n % 10 + '0', fd);
	}
	else
		len += ft_putchar_len(n + '0', fd);
	return (len);
}

int	ft_putnbr_len(int n, int fd)
{
	int	len;

	len = 0;
	len = writenum(len, n, fd);
	if (len < 0)
		return (-1);
	return (len);
}
