/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:13:51 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 16:45:40 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_error(char *str, int fd)
{
	write(fd, "Error\n", 6);
	write(fd, str, ft_strlen(str));
	exit(1);
}
