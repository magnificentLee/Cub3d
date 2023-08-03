#include "mapping.h"

void	playerRendering(t_config *config)
{
	double	posMidX;
	double	posMidY;
	int		i;
	int		j;
	
	posMidX = config->r_pos.posX;
	posMidY = config->r_pos.posY;
	printf("%f:%f\n", config->r_pos.posY, config->r_pos.posX);
//	posMidX = (config->r_pos.posX + (double)TEX_WIDTH) / 2 - 1;
//	posMidY = (config->r_pos.posY + (double)TEX_WIDTH) / 2 - 1;
	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			config->buf[(int)posMidY * 32 + j][(int)posMidX * 32 + i] = 0x00FF00;
			i++;
		}
		j++;
	}
}
/*
void	playerMovement(t_config *config, int addX, int addY)
{
	double	nextX;
	double	nextY;
	int		i;
	int		j;

	nextX = config->r_pos.posX + addX;
	nextY = config->r_pos.posY + addY;
//	검증 부분은 나중에
//	if (config->map[nextY][nextX])
	if (config->map[(int)nextY][(int)nextX] == '1')
		return ;
	config->r_pos.posX = nextX;
	config->r_pos.posY = nextY;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			config->buf[(int)nextY + j][(int)nextX + i] = 

		}
	}
}
*/