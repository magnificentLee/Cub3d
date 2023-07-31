/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmil <jeongmil@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:45 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/31 20:49:53 by jeongmil         ###   ########seoul.kr  */
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
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define MAX_PATH_LEN 256
# define MAX_RGB_LEN 11

# define NUMBER_OF_IMG	5
# define TEX_WIDTH 		64 // size of img_file 현재 사용중인 이미지는 64 * 64 크기, 간격을 생성하려면 65 이상으로 수정
# define TEX_HEIGH		64
# define WIN_WIDTH 		640 // 640 // 가로, winRowSize >= tileSize * config->max_rows, 테스트 케이스의 경우 2200 >= 65 * 33 , 해당 사이즈에선 버퍼가 너무 커서 런타임 에러 발생
# define WIN_HEIGH 		480 // 480 // 세로, winColSize >= tileSize * config->max_cols, 테스트 케이스의 경우 1080 >= 65 * 14 , 해당 사이즈에선 버퍼가 너무 커서 런타임 에러 발생

typedef struct s_img {
	void	*img;
	int		*data; // img의 데이터를 뽑아서 textures에 할당하는 경우 구조체가 아닌 지역변수로 할당하는 경우 데이터의 수명에 문제가 생겨 UB가 발생할 수 있음
	int		img_width; // TEX_WIDTH 와 동일, 이 값으로 대체 가능
	int		img_height; // TEX_HEIGH 과 동일, 이 값으로 대체 가능
	int		bpp;		// bit per pixel 한 픽셀의 RGBA값을 저장하는데 사용된 메모리
	int		endian;		// 빅 or 리틀 엔디안
	int		size_l; // 
	
}	t_img;

/* s_config 와 통합 예정?
typedef struct s_rayInfo
{
	double	posX;
	double	poxY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	rayDirX;
	double	rayDirY;	
}	t_rayInfo;
*/

typedef struct s_config {
	void	*mlx;
	void	*win;
	int		win_rows;
	int		win_cols;
	t_img	img;
	int		**textures;
	char	north_texture[MAX_PATH_LEN];
	char	south_texture[MAX_PATH_LEN];
	char	west_texture[MAX_PATH_LEN];
	char	east_texture[MAX_PATH_LEN];
	char	floor_color[MAX_RGB_LEN];
	char	ceiling_color[MAX_RGB_LEN];
	char	**map;
	int		**buf; // 한 번에 출력하는 용도
//	int		buf[WIN_HEIGH][WIN_WIDTH]; // 이중배열을 사용하는 경우 맵이 크면 스택메모리 부족으로 터진다
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

/* test initialize */
void		initialize(t_config *config, char **av);

/* test Parsing */
void		map_size(t_config *config, char *line);
void		map_reading(char *file, t_config *config);

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


#endif