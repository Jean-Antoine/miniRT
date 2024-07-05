/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 15:01:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"



int	ft_color_at(t_scene *scene, t_ray ray)
{
	t_inters	*hit;
	t_color		color;	

	ft_inters(*scene, &ray);
	hit = ft_hit(&ray.inters_lst);
	if (hit)
	{
		color = ft_get_color_at_point(*hit, scene);
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
	printf("Computing...\n");
	while (++x < SIZE_H)
	{
		y = -1;
		while (++y < SIZE_V)
		{
			ray = ft_pixel_to_ray(x, y, &scene->camera);
			canvas[x][y] = ft_color_at(scene, ray);
		}
	}
	printf("Computing done\n");
	return (EXIT_SUCCESS);
}
