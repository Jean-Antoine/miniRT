/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:32:20 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/20 11:48:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H
# include "parsing.h"
# include "vector.h"
# include "matrix.h"
# include <stdio.h>
# include <math.h>
# define SIZE_H 600
# define SIZE_V 600
# define M_PI 3.14159265358979323846

typedef struct s_inters
{
	t_object			*object;
	double				t;
	struct s_inters		*next;
}	t_inters;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
	t_inters	*inters_lst;
}	t_ray;

void		ft_mat_sphere(t_object *sphere);
void		ft_mat_obj(t_object *list);
t_ray		ft_ray(t_point origin, t_vector direction);
t_ray		ft_pixel_to_ray(int px, int py, t_camera *camera);
t_ray		ft_transform(t_ray ray, t_mat mat);
int			ft_compute(t_scene *scene, int canvas[SIZE_H][SIZE_V]);
int			ft_new_inters(t_inters **lst, t_object *object, double t);
int			ft_inters_sphere(t_object *sphere, t_ray *ray);
t_inters	*ft_hit(t_inters **lst);
void		ft_free_inters_lst(t_inters *inters);
t_vector	ft_get_normal_at_sp(t_object sphere, t_point world_point);
t_vector	ft_reflect(t_vector in, t_vector normal);
t_color	ft_get_color_at_point(t_object obj, t_point pt, t_light light, t_scene scene);



#endif