/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/10 14:57:39 by lpaquatt         ###   ########.fr       */
=======
/*   Updated: 2024/06/10 14:21:06 by jeada-si         ###   ########.fr       */
>>>>>>> adcbd66922d2553ca0f281f185f273b23272fa36
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

	direction = ft_v_set((double)x * 10 / (double)scene->size_y - 5 * (double)SIZE_X / (double)scene->size_y, (double)y * 10 / (double)scene->size_y - 5 , 15);
	ray = ft_create_ray(scene->camera.position, direction);
	ft_inters_sphere(scene->objects, &ray);
	if (ft_hit(&ray.inters_lst))
	{
		ft_free_inters_lst(ray->inters_lst);
		free(ray);
		return (0xFF0000);
	}
	ft_free_inters_lst(ray->inters_lst);
	free(ray);
	return (0xFFFFFF);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y])
{
	size_t	x;
	size_t	y;

	ft_mat_obj(scene->objects);
	x = -1;
	scene->size_y = SIZE_Y * (size_t) scene->camera.fov / 180;
	while (++x < SIZE_X)
	{
		y = -1;
		while (++y < scene->size_y)
			canvas[x][y] = ft_get_color_pixel(scene, x, y);
	}
	return (EXIT_SUCCESS);
}
