#ifndef MAPPING_H
# define MAPPING_H

#include "cub3d.h"

# define tileSize 65 // size of img_file 현재 사용중인 이미지는 64 크기임, 간격을 없애려면 64로 수정
# define winRowSize 2200 // 가로, winRowSize >= tileSize * config->max_rows, 테스트 케이스의 경우 2200 >= 65 * 33
# define winColSize 1080  // 세로, winColSize >= tileSize * config->max_cols, 테스트 케이스의 경우 1080 >= 65 * 14

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		win_row;
	int		win_col;
	void	*img_floor;
	void	*img_wall;
	void	*img_north;
	void	*img_empty;
	double	posX;
	double	posY;

}	t_mlx;

// tmp struct for raycasting
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


// mapping.c
void		init_texture(t_mlx *mlx);
void		mapping(t_config *config, t_mlx *mlx);
void		put_image_to_window(t_mlx *mlx, void *img_file, int i, int j);
void		put_image_to_window_empty(t_mlx *mlx, char sep, int i, int j);
void		put_player_to_window(t_mlx *mlx, int i, int j);

// event.c
int			key_press(int keycode, t_mlx *mlx);
int			mouth_press(t_mlx *mlx);


#endif