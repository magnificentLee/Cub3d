/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:26:31 by jeongmil          #+#    #+#             */
/*   Updated: 2023/08/03 20:13:10 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPPING_H
# define MAPPING_H

# include "../cub3d.h"

typedef struct s_img	t_img;
typedef struct s_pos	t_pos;
typedef struct s_config	t_config;

/* test Mapping */
void		draw_map(t_config *config);
void		mapping(t_config *config);

/* test image_textures */
int			init_texture(t_config *config);
void		load_textures(t_config *config);
void		load_image(t_config *config, char *img_file, int *texture);
int			free_textures(int **integer, int count);

/* test Event */
int			key_press(int keycode, t_config *config);
int			mouth_press(t_config *config);

// player.c
void		playerRendering(t_config *config);

#endif