/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:26:38 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/18 20:47:35 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_space(char space)
{
	if (space == '\t' || space == '\n' || space == '\v' || \
		space == '\f' || space == '\r' || space == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int						minus;
	unsigned long long		result;
	unsigned long long		over;

	minus = 1;
	result = 0;
	over = 9223372036854775807;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	if (result > over && minus == 1)
		return (-1);
	else if (result > over + 1 && minus == -1)
		return (0);
	return (result * minus);
}
