/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:14:25 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/27 16:42:48 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	row_cnt(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str == 0)
		return (0);
	while (str[i] && str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		count++;
		while (str[i] && str[i] != c)
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static char	*copy(const char *str, int size)
{
	int		i;
	char	*sepr_row;

	sepr_row = (char *)malloc(sizeof(char) * (size + 1));
	if (sepr_row == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sepr_row[i] = str[i];
		i++;
	}
	sepr_row[i] = '\0';
	return (sepr_row);
}

static int	word_cnt(char const	*str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	ft_split_free2(char **s, int i)
{
	while (i-- > 0)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**sepr;
	int		row;
	int		word_len;
	int		index;

	row = row_cnt(s, c);
	sepr = (char **)malloc(sizeof(char *) * (row + 1));
	if (sepr == NULL)
		return (NULL);
	index = -1;
	while (++index < row)
	{
		while (*s && *s == c)
			s++;
		word_len = word_cnt(s, c);
		sepr[index] = copy(s, word_len);
		if (sepr[index] == NULL)
		{
			ft_split_free2(sepr, index);
			return (0);
		}
		s += word_len;
	}
	sepr[row] = 0;
	return (sepr);
}
