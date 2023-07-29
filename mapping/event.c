/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:09:34 by jeongmil          #+#    #+#             */
/*   Updated: 2023/07/29 20:02:52 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_config *config)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(config->mlx, config->win);
		exit(0);
	}
	return (0);
}

int	mouth_press(t_config *config)
{
	mlx_destroy_window(config->mlx, config->win);
	exit(0);	
}
