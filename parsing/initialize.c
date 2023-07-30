#include "../cub3d.h"

void	initialize(t_config *config, char **av)
{
	int	i;
	int	j;

	config->mlx = mlx_init();
	config->map_rows = 0;
	config->map_cols = 0;
	j = 0;
	while (j < WIN_HEIGH)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			config->buf[j][i] = 0;
			i++;			
		}
		j++;
	}
	map_reading(av[1], config); // parsing
	config->win = mlx_new_window(config->mlx, WIN_WIDTH, WIN_HEIGH, "mlx_test");
}