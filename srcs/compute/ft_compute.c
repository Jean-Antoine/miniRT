/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/20 11:18:59 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_point	ft_compute_point_on_ray(t_ray ray, double t)
{
	return (ft_p_translate(ray.origin, ft_v_scalar_prod(t, ray.direction)));
}


int	ft_color_to_int(t_color color) 
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

int	ft_get_color_pixel(t_scene *scene, size_t x, size_t y)
{
	t_ray		ray;
	t_inters	*hit;
	t_color		color;	

	ray = ft_pixel_to_ray(x, y, &scene->camera);
	ft_inters_sphere(scene->objects, &ray);
	hit = ft_hit(&ray.inters_lst);
	if (hit)
	{
		return (0xFF0000);
		color = ft_get_color_at_point(*hit->object, ft_compute_point_on_ray(ray, hit->t), *scene->lights, *scene); //lights
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

	ft_mat_obj(scene->objects);
	x = -1;
	while (++x < SIZE_H)
	{
		y = -1;
		while (++y < SIZE_V)
			canvas[x][y] = ft_get_color_pixel(scene, x, y);
	}
	return (EXIT_SUCCESS);
}
