/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:34:23 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/28 13:35:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H

# include "mini_rt.h"
# define INVALID_MSG "Invalid data: "


size_t	ft_tabsize(char	**tab);
int		ft_error(char *str, int use_errno);

int		ft_open_file(char *file_name);
int		ft_parse(t_scene *scene, char *file);
int		ft_parse_line(char *line, t_scene *scene);
int		ft_parse_object(char **args, t_object **dest);
int		ft_parse_light(char **args, t_light **dest);
int		ft_parse_camera(char **args, t_camera *dest);

int		ft_set_point(t_point *dest, char *str);
int		ft_set_vector(t_vector *dest, char *str);
int		ft_set_scalar(double *dest, char *str);
int		ft_set_color(t_color *color, char *str);

int		ft_is_numeric(char *str);
int		ft_is_float(char *str);
int		ft_is_triplet(char **tab);
int		ft_is_normalized(t_vector vector);

#endif