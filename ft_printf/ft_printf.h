/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:26:59 by krazikho          #+#    #+#             */
/*   Updated: 2023/12/21 20:27:41 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_len(char c, int fd);
int	ft_puthex_len(unsigned long num, char format, int fd);
int	ft_putnbr_len(int n, int fd);
int	ft_putptr_len(void *ptr, int fd);
int	ft_putstr_len(char *s, int fd);
int	ft_putunbr_len(unsigned int n, int fd);

#endif
