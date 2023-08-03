/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:32:34 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 15:50:50 by jeongmil         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct s_img	t_img;
typedef struct s_pos	t_pos;
typedef struct s_config	t_config;

// initialize.c
void		initialize_config(t_config *config);
void		set_player_pos(t_config *config);
void		parsing_cub(char *file_path, t_config *config);
void		initialize(t_config *config, char **av);

// get_color_texture.c
void		get_texture(char *line, t_config *config);
void		get_color(char *line, t_config *config);

//parse_check.c
void		check_file_extension(char *file_path);

// parse_error.c
void		parse_error(char *str, int fd);

// parsing.c
void		parse_line(char *line, t_config *config);
void		parse_config(char *file_path, t_config *config);
void		remove_next_line(char *line);

// valid_color_texture.c
int			is_valid_rgb(char *rgb_str);
int			is_valid_texture_path(char *path);
int			is_texture(char *line);
int			is_color(char *line);

// process_map_line.c
void		process_map_line(char *line, t_config *config);
void		fill_map(char *file_path, t_config *config);

#endif