/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:07:10 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/21 20:48:19 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_len(char *s, int fd)
{
	int	len;

	if (s == NULL)
	{
		if (write(fd, "(null)", 6) == -1)
		{
			return (-1);
		}
		return (6);
	}
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	if (write(fd, s, len) == -1)
	{
		return (-1);
	}
	return (len);
}
