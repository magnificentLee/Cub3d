#include "../cub3d.h"

void	map_reading(char *file, t_config *config)
{
	int		fd;
	char	*res;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	res = ft_strdup("");
	while (line)
	{
		map_size(config, line);
		tmp = res;
		res = ft_strjoin(res, line);
		config->map_rows++;
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	config->map = ft_split(res, '\n');
	free(res);
}

void	map_size(t_config *config, char *line)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			width++;
		i++;
	}
	if (width > config->map_cols)
		config->map_cols = width;
}
