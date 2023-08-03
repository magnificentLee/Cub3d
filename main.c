/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:21:17 by sejokim           #+#    #+#             */
/*   Updated: 2023/08/03 14:51:49 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_config(t_config *config)
{
	config->map = NULL;
	config->map_rows = 0;
	config->map_cols = 0;
	config->no_tex = NULL;
	config->so_tex = NULL;
	config->we_tex = NULL;
	config->ea_tex = NULL;
	config->floor_color = -1;
	config->ceiling_color = -1;
	config->map_started = 0;
	config->news_flag = 0;
}

// void	map_check(t_config *config)
// {
	
// }

void	set_player_pos(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (config->map[i])
	{
		j = 0;
		while (config->map[i][j])
		{
			if (config->map[i][j] == 'W' || config->map[i][j] == 'E' \
			|| config->map[i][j] == 'S' || config->map[i][j] == 'N')
			{
				config->p_pos.x = j + 0.501;
				config->p_pos.y = i + 0.501;
			}
			j++;
		}
		i++;
	}
}

void	parsing_cub(char *file_path, t_config *config)
{
	parse_config(file_path, config);
	// map_check(config);
	set_player_pos(config);
}

int	main(int ac, char **av)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		parse_error("malloc failed.\n", 2);
	if (ac != 2)
	{
		printf("Usage: %s [config_file]\n", av[0]);
		free(config);
		return (1);
	}
	parsing_cub(av[1], config);
	printf("%f\n", config->p_pos.x);
	printf("%f\n", config->p_pos.y);
	printf("%d\n", config->map_rows);
	free(config);
}
