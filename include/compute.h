/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:32:20 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/06 14:55:19 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H
# include "parsing.h"
# include "vector.h"
# include "matrix.h"
# include <stdio.h>
# define SIZE_X 800
# define SIZE_Y 450

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

int			ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y]);
void		ft_set_transform_sp(t_object *sphere);
t_ray		ft_transform(t_ray ray, t_mat mat);
int			ft_intersect_sphere(t_object *sphere, t_ray *ray);
t_ray		*ft_create_ray(t_point origin, t_vector direction);
int			ft_new_insters_addback(t_inters **lst, t_object *object, double t);
t_inters	*ft_hit(t_inters **lst);

#endif