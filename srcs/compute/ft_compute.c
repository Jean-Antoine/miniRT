/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:04:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 15:17:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_prepare_computations(t_ray ray, t_inters *inters)
{
	inters->comp.point = ft_position(ray, inters->t);
	inters->comp.eye_v = ft_v_scalar_prod(-1, ray.direction);
	inters->comp.color_at_pt = ft_color_at_point(inters->object, inters->comp.point);
	inters->comp.normal_v = ft_normal_at(inters->object, inters->comp.point);
	inters->comp.inside = FALSE;
	if ((inters->object->type == sphere
		|| inters->object->type == cylinder
		|| inters->object->type == cone)
		&& ft_v_dot_prod(inters->comp.normal_v, inters->comp.eye_v) < TOLERANCE)
	{
		inters->comp.inside = TRUE;
		inters->comp.normal_v = ft_v_scalar_prod(-1, inters->comp.normal_v);
	}
}

static void	ft_color_at(t_scene *scene, t_ray ray, int *dest)
{
	t_inters	*hit;
	t_color		color;

	hit = ft_hit(&ray.inters_lst);
	*dest = ft_color_to_int(ft_black());
	if (!hit)
		return (ft_free_inters_lst(ray.inters_lst));
	ft_prepare_computations(ray, hit);
	color = ft_get_color_at_point(*hit, scene);
	*dest = ft_color_to_int(color);
	ft_free_inters_lst(ray.inters_lst);
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
			if (ft_inters(scene, &ray))
				return (EXIT_FAILURE);
			ft_color_at(scene, ray, &(canvas[x][y]));
		}
	}
	printf("Computing done\n");
	return (EXIT_SUCCESS);
}
