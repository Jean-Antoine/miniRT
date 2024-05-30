/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/30 17:21:05 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

//Scenario: Creating and querying a ray
t_ray	ft_create_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

//Scenario: Computing a point from a distance
t_point	ft_compute_point_on_ray(t_ray ray, double t)
{
	return (ft_p_translate(ray.origin, ft_v_scalar_prod(t, ray.direction)));
}

int	ft_get_color_pixel(t_scene *scene, size_t x, size_t y)
{
	(void) scene;
	(void) x;
	(void) y;
	return (EXIT_SUCCESS);
}

int	ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y])
{
	size_t	x;
	size_t	y;

	x = 0;
	scene->size_y = SIZE_Y * (size_t)scene->camera.fov / 180;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < scene->size_y)
		{
			canvas[x][y] = ft_get_color_pixel(scene, x, y);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}