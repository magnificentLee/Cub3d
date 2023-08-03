/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:43:13 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/28 20:48:32 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file_extension(char *file_path)
{
	int	len;

	len = ft_strlen(file_path);
	if (len < 5 || ft_strcmp(file_path + len - 4, ".cub") != 0)
	{
		printf("Error\nInvalid file extension\n");
		exit(1);
	}
}
