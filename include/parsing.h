/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:23 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 15:49:48 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

int	ft_parse_line(char *line, t_scene *scene);
int	ft_parse(t_scene *scene, char *file);
int	ft_open_file(char *file_name);
t_color	ft_set_color(int r, int g, int b);
int	ft_set_light_brightness(double *brightness, char *arg);
int	ft_set_color_from_arg(t_color *color, char *str);
t_light	*ft_new_light_addback(t_light **light_lst);
int	ft_create_ambiant_light(char **args, t_scene *scene);

#endif