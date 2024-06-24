/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/24 17:59:21 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static double	ft_dmin(double x, double y)
{
	if (x > y)
		return (y);
	return (x);
}

int	ft_color_to_int(t_color color) 
{	
	return (((int)(ft_dmin(color.x * 255.0, 255)) << 16)
		+ ((int)(ft_dmin(color.y * 255.0, 255)) << 8)
		+ (int)(ft_dmin(color.z * 255.0, 255)));
}

t_ray	ft_manual_ray(int x, int y)
{
	double		world_x;
	double		world_y;
	double		half;
	double		pixel_size;
	t_ray		ray;

	pixel_size = 7.0 / (double) SIZE_V;
	half = 7.0 / 2.0;
	world_y = half - pixel_size * y;
	world_x = -half + pixel_size * x;
	ray = ft_ray(
		ft_point(0, 0, -5),
		ft_v_normalize(
			ft_p_to_v(
				ft_point(0, 0, -5),
				ft_point(world_x, world_y, 7)
			)
		)
	);
	return (ray);
}

int	ft_color_at(t_scene *scene, t_ray ray)
{
	t_inters	*hit;
	t_color		color;	
	t_object	*object;

	object = scene->objects;
	while (object)
	{
		ft_inters_sphere(object, &ray);
		object = object->next;
	}
	hit = ft_hit(&ray.inters_lst);
	if (hit)
	{
		color = ft_get_color_at_point(
			hit->object,
			ft_position(ray, hit->t),
			ft_v_scalar_prod(-1.0, ft_v_normalize(ray.direction)),
			scene);
		ft_free_inters_lst(ray.inters_lst);
		return (ft_color_to_int(color));
	}
	ft_free_inters_lst(ray.inters_lst);
	return (0x000000);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_H][SIZE_V])
{
	size_t	x;
	size_t	y;
	t_ray	ray;

	ft_mat_obj(scene->objects);
	x = -1;
	while (++x < SIZE_H)
	{
		y = -1;
		while (++y < SIZE_V)
		{
			
			ray = ft_pixel_to_ray(x, y, &scene->camera);
			// ray = ft_manual_ray(x, y);
			canvas[x][y] = ft_color_at(scene, ray);
		}
	}
	return (EXIT_SUCCESS);
}
