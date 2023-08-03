/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:45 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 14:47:01 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./utils/utils.h"
# include "./parsing/parsing.h"

# define BUFFER_SIZE 4242
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define WINDOW_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

#endif