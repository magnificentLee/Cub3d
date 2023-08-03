/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:45 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 17:40:32 by sejokim          ###   ########.fr       */
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
# include "./mapping/mapping.h"

# define BUFFER_SIZE 4242
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define WINDOW_EXIT			17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define NUMBER_OF_IMG	5
# define TEX_WIDTH 		64 // size of img_file 현재 사용중인 이미지는 64 * 64 크기, 간격을 생성하려면 65 이상으로 수정
# define TEX_HEIGH		64
# define WIN_WIDTH 		640
# define WIN_HEIGH 		480
# define SIZEVALUE		2 // 2 means half size

typedef struct s_img {
	void	*img;
	int		*data; // img의 데이터를 뽑아서 textures에 할당하는 경우 구조체가 아닌 지역변수로 할당하는 경우 데이터의 수명에 문제가 생겨 UB가 발생할 수 있음
	int		img_width; // TEX_WIDTH 와 동일, 이 값으로 대체 가능
	int		img_height; // TEX_HEIGH 과 동일, 이 값으로 대체 가능
	int		bpp;		// bit per pixel 한 픽셀의 RGBA값을 저장하는데 사용된 메모리
	int		endian;		// 빅 or 리틀 엔디안
	int		size_l; //
}	t_img;

typedef struct s_pos
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	rayDirX;
	double	rayDirY;	
}	t_pos;

typedef struct s_fc_set
{
	int	no_tex_set;
	int	so_tex_set;
	int	we_tex_set;
	int	ea_tex_set;
	int	floor_set;
	int	ceiling_set;
}	t_fc_set;

typedef struct s_config {
	void		*mlx;
	void		*win;
	int			win_rows;
	int			win_cols;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	int			floor_color;
	int			ceiling_color;
	int			map_started;
	int			news_flag;
	t_img		img;
	t_pos		r_pos; // t_p_pos :: ray_position
	int			**textures;
	char		**map;
	int			**buf; // 한 번에 출력하는 용도
	int			map_rows;
	int			map_cols;
	t_fc_set	fc_set;
}	t_config;

// main.c
int			check_not_valid(int ac, char **av, t_config *config);

#endif