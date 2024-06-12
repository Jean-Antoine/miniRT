/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/11 15:49:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_point	ft_compute_point_on_ray(t_ray ray, double t)
{
	return (ft_p_translate(ray.origin, ft_v_scalar_prod(t, ray.direction)));
}

int	ft_get_color_pixel(t_scene *scene, size_t x, size_t y)
{
	t_ray		ray;
	t_vector	direction;

	direction = ft_v_set((double)x * 10 / (double)SIZE_Y - 5 * (double)SIZE_X / (double)SIZE_Y, 
		(double)y * 10 / (double)SIZE_Y - 5 , 15);
	ray = ft_create_ray(scene->camera.position, direction);
	ft_inters_sphere(scene->objects, &ray);
	if (ft_hit(&ray.inters_lst))
	{
		ft_free_inters_lst(ray.inters_lst);
		return (0xFF0000);
	}
	ft_free_inters_lst(ray.inters_lst);
	return (0xFFFFFF);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y])
{
	size_t	x;
	size_t	y;

	ft_mat_obj(scene->objects);
	x = -1;
	while (++x < SIZE_X)
	{
		y = -1;
		while (++y < SIZE_Y)
			canvas[x][y] = ft_get_color_pixel(scene, x, y);
	}
	return (EXIT_SUCCESS);
}
