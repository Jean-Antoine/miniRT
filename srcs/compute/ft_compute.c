/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/21 11:43:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

int	ft_color_to_int(t_color color) 
{
	return (((int) color.x << 16) | (((int) color.y / 255) << 8) | ((int)color.z / 255));
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
		color = ft_get_color_at_point(
			*hit->object,
			ft_position(ray, hit->t),
			*scene->lights,
			*scene);
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
