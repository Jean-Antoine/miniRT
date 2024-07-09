/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 16:00:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

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
			if (ft_inters(scene, &ray))
				return (EXIT_FAILURE);
			ft_color_at(scene, ray, &(canvas[x][y]));
		}
	}
	printf("Computing done\n");
	return (EXIT_SUCCESS);
}
