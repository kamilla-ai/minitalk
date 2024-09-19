/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:10 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/21 20:38:09 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_len(unsigned long num, char format, int fd)
{
	char	*base;
	int		chars_printed;
	int		temp;

	chars_printed = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num >= 16)
	{
		temp = ft_puthex_len(num / 16, format, 1);
		if (temp == -1)
			return (-1);
		chars_printed += temp;
	}
	if (write(fd, &base[num % 16], 1) == -1)
		return (-1);
	chars_printed++;
	return (chars_printed);
}
