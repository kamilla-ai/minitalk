/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:35:35 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/22 15:09:39 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_len(void *ptr, int fd)
{
	int	len;
	int	temp;

	len = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	temp = ft_puthex_len((unsigned long)ptr, 'x', fd);
	if (temp == -1)
	{
		return (-1);
	}
	len += temp;
	return (len);
}
