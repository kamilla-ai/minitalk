/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krazikho <krazikho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:43:33 by krazikho          #+#    #+#             */
/*   Updated: 2024/07/22 14:12:50 by krazikho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	skip_whitespace(const char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
	{
		(*i)++;
	}
}

static long	convert_str_to_num(const char *str, int *i)
{
	long	num;

	num = 0;
	while (str[*i])
	{
		if ((str[*i] >= '0' && str[*i] <= '9'))
		{
			if ((num > 2147483647 / 10) || (num == 2147483647 / 10
					&& str[*i] > '7'))
				return (-1);
			num = num * 10 + (str[*i] - '0');
			(*i)++;
		}
		else if (str[*i] == ' ')
			(*i)++;
		else
			return (-1);
	}
	return (num);
}

static int	isonlyspaces(const char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

long	mt_atoi(const char *str)
{
	int		i;
	long	num;

	if (str[0] == '\0' || isonlyspaces(str))
	{
		return (-1);
	}
	i = 0;
	num = 0;
	skip_whitespace(str, &i);
	num = convert_str_to_num(str, &i);
	return (num);
}
