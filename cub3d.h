/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:45 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/28 17:53:09 by jeongmil         ###   ########seoul.kr  */
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

# define BUFFER_SIZE 4242
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define WINDOW_EXIT			17

# define KEY_ESC		53
# define KEY_W			1
# define KEY_A			0
# define KEY_S			13
# define KEY_D			2

# define MAX_PATH_LEN 256
# define MAX_RGB_LEN 11

typedef struct s_config {
	char	north_texture[MAX_PATH_LEN];
	char	south_texture[MAX_PATH_LEN];
	char	west_texture[MAX_PATH_LEN];
	char	east_texture[MAX_PATH_LEN];
	char	floor_color[MAX_RGB_LEN];
	char	ceiling_color[MAX_RGB_LEN];
	char	**map;
	int		map_rows;
	int		map_cols;
}	t_config;


/* parsing function */
/*
int			check_rgb_range(char *rgb);
void		add_line_to_map(char *line, t_config *config);
void		parse_line(char *line, t_config *config);
void		check_file_extension(char *file_path);
t_config	parse_config(char *file_path);
*/
/* utility function */
char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
int			find_newline(char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strncpy(char *dest, const char *src, size_t n);
int			ft_isdigit(int c);
void		ft_split_free(char **strs, int count);
int			is_space(char space);
int			ft_atoi(char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* test Parsing */
void		map_size(t_config *config, char *line);
void		map_reading(char *file, t_config *config);


#endif