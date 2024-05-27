/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:23 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 11:51:50 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

int	ft_parse_scene(t_scene *scene, char *file);
int	ft_open_file(char *file_name);
t_color	ft_create_color(int r, int g, int b);
int	ft_create_color_from_arg(t_color *color, char *str);
t_light	*ft_new_light_addback(t_light **light_lst);
int	ft_create_ambiant_light(char **args, t_scene *scene);
int	ft_fill_scene(char *line, t_scene *scene);
int	ft_create_scene(int fd, t_scene *scene);


#endif