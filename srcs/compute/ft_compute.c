/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/11 17:31:55 by jeada-si         ###   ########.fr       */
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

	ray = ft_pixel_to_ray(x, y, &scene->camera);
	ft_inters_sphere(scene->objects, &ray);
	if (ft_hit(&ray.inters_lst))
	{
		ft_free_inters_lst(ray.inters_lst);
		return (0xFF0000);
	}
	ft_free_inters_lst(ray.inters_lst);
	return (0xFFFFFF);
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
