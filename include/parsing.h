/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:23 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 17:40:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

int		ft_parse_line(char *line, t_scene *scene);
int		ft_parse(t_scene *scene, char *file);
int		ft_open_file(char *file_name);
int		ft_set_brightness(double *brightness, char *arg);
int		ft_set_color(t_color *color, char *str);
int		ft_error(char *str, int use_errno);
int		ft_parse_line(char *line, t_scene *scene);
int		ft_parse(t_scene *scene, char *file);
int		ft_open_file(char *file_name);
int		ft_is_numeric(char *str);
int		ft_is_float(char *str);
int		ft_is_triplet(char **tab);
int		ft_is_normalized(t_vector vector);
int		ft_get_point(t_point *dest, char *str);
int		ft_get_vector(t_vector *dest, char *str);
int		ft_get_scalar(int *dest, char *str);
t_color	ft_create_color(int r, int g, int b);
int		ft_create_color_from_arg(t_color *color, char *str);
t_light	*ft_new_light_addback(t_light **light_lst);
int		ft_create_ambiant_light(char **args, t_scene *scene);
int		ft_create_spot_light(char **args, t_scene *scene);

#endif