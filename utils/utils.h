/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:01:03 by sejokim           #+#    #+#             */
/*   Updated: 2023/07/30 15:51:22 by sejokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../cub3d.h"

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
int			ft_str_is_numeric(char *str);
int			my_isdigit(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			is_empty_line(char *line);
int			is_map_line(char *line);
int			ft_isspace(char c);
char		*ft_strchr(const char *s, int c);

#endif