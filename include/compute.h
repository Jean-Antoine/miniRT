/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:32:20 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 17:28:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H
# include "parsing.h"
# include "vector.h"
# include "matrix.h"
# include <stdio.h>
# include <math.h>
# define SIZE_H 1000
# define SIZE_V 1000
# define M_PI 3.14159265358979323846
# define CHECKERS_BY_UNIT 2

typedef struct s_light_comp
{
	t_vector	normal_v;
	t_vector	light_v;
	t_vector	reflect_v;
	double		light_dot_normal;
	double		reflect_dot_eye;
}	t_light_comp;

typedef struct s_inters_comp
{
	t_point		point;
	t_color		color_at_pt;
	t_color		ambient;
	t_vector	eye_v;
	t_vector	normal_v;
	t_bool		inside;
}	t_inters_comp;

typedef struct s_inters
{
	t_object			*object;
	double				t;
	t_inters_comp		comp;
	struct s_inters		*next;
}	t_inters;

typedef struct s_ray
{
	t_point				origin;
	t_vector			direction;
	t_inters			*inters_lst;
}	t_ray;

typedef struct s_discr
{
	double	a;
	double	b;
	double	c;
	double	d;
	int		n;
	double	t0;
	double	t1;
}	t_discr;

void		ft_mat_obj(t_object *list);
void		ft_ambient_obj(t_object *object, double brightness,	t_color color);
t_ray		ft_ray(t_point origin, t_vector direction);
t_point		ft_position(t_ray ray, double t);
t_ray		ft_pixel_to_ray(int px, int py, t_camera *camera);
t_mat		ft_mat_view(t_vector forward, t_vector left, t_vector up,
				t_point origin);
t_ray		ft_transform(t_ray ray, t_mat mat);
int			ft_compute(t_scene *scene, int canvas[SIZE_H][SIZE_V]);
int			ft_add_inters(t_ray *ray, t_object *object, double t);
t_discr		ft_discriminant(t_object *object, t_ray *ray);
int			ft_inters(t_scene *scene, t_ray *ray);
int			ft_inters_cyl(t_object *cyl, t_ray *ray, t_ray *dest);
t_inters	*ft_hit(t_inters **lst);
void		ft_free_inters_lst(t_inters *inters);
t_vector	ft_normal_at(t_object *sphere, t_point world_point);
t_vector	ft_reflect(t_vector in, t_vector normal);
t_color		ft_get_color_at_point(t_inters hit, t_scene *scene);
t_color		ft_lighting(t_light_comp l, t_inters hit, t_light *light,
				t_scene *scene);
t_color		ft_get_uv_color_img(t_img texture, double u, double v);
t_point		ft_get_uv_cy(t_point point);
t_point		ft_get_uv_sp(t_point point);
int			ft_color_to_int(t_color color);
t_color		ft_int_to_color(unsigned int color);
t_color		ft_white(void);
t_color		ft_black(void);
t_color		ft_grey(void);

#endif