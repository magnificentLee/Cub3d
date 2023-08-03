/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:09:34 by jeongmil          #+#    #+#             */
/*   Updated: 2023/08/03 17:27:01 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

int	key_press(int keycode, t_config *config)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(config->mlx, config->win);
		exit(0);
	}
	else if (keycode == KEY_S)
	{
		
	}
	
	return (0);
}

int	mouth_press(t_config *config)
{
	mlx_destroy_window(config->mlx, config->win);
	exit(0);
}
