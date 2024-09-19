/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:26:55 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/22 15:00:52 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}

static int	ft_putarg(va_list args, char format)
{
	if (format == 'c')
		return (ft_putchar_len(va_arg(args, int), 1));
	else if (format == 's')
		return (ft_putstr_len(va_arg(args, char *), 1));
	else if (format == 'p')
		return (ft_putptr_len(va_arg(args, void *), 1));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_len(va_arg(args, int), 1));
	else if (format == 'u')
		return (ft_putunbr_len(va_arg(args, unsigned int), 1));
	else if (format == 'x' || format == 'X')
		return (ft_puthex_len(va_arg(args, unsigned int), format, 1));
	else if (format == '%')
		return (ft_putchar_len('%', 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars_printed;
	int		temp;

	va_start(args, format);
	chars_printed = 0;
	while (*format != '\0')
	{
		temp = chars_printed;
		if (*format == '%' && ft_strchr("cspdiuxX%", *(format + 1)))
		{
			format++;
			chars_printed += ft_putarg(args, *format);
		}
		else
		{
			chars_printed += ft_putchar_len(*format, 1);
		}
		format++;
		if (chars_printed < temp)
			return (-1);
	}
	va_end(args);
	return (chars_printed);
}
