/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:36:05 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 14:36:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_color	ft_checker_at_point_sp(t_object *sphere, t_point point)
{
	t_point	uv;

	uv = ft_get_uv_sp(point);
	if ((int)(floor(uv.x * CHECKERS_BY_UNIT * 6)
		+ floor(uv.y * CHECKERS_BY_UNIT * 6)) % 2 == 0)
		return (ft_color_mix(sphere->material.color, ft_grey()));
	return (sphere->material.color);
}

static t_color	ft_checker_at_point_cy(t_object *sphere, t_point point)
{
	t_point	uv;

	uv = ft_get_uv_cy(point);
	if ((int)(floor(uv.x * CHECKERS_BY_UNIT * 6)
		+ floor(uv.y * CHECKERS_BY_UNIT * 3)) % 2 == 0)
		return (ft_color_mix(sphere->material.color, ft_grey()));
	return (sphere->material.color);
}

static t_color	ft_color_at_point(t_object *object, t_point point)
{
	if (object->material.pattern == TRUE)
	{
		point = ft_mat_prod_tup(object->transform, point);
		if (object->type == sphere)
			return (ft_checker_at_point_sp(object, point));
		if (object->type == cylinder)
			return (ft_checker_at_point_cy(object, point));
		point = ft_v_scalar_prod(CHECKERS_BY_UNIT, point);
		if ((int)(floor(point.x + TOLERANCE) + floor(point.y + TOLERANCE)
			+ floor(point.z + TOLERANCE)) % 2 == 0)
			return (ft_color_mix(object->material.color, ft_grey()));
		return (object->material.color);
	}
	return (object->material.color);
}

static void	ft_prepare_computations(t_ray ray, t_inters *inters)
{
	inters->comp.point = ft_position(ray, inters->t);
	inters->comp.eye_v = ft_v_scalar_prod(-1, ray.direction);
	inters->comp.color_at_pt = ft_color_at_point(inters->object,
			inters->comp.point);
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

void	ft_color_at(t_scene *scene, t_ray ray, int *dest)
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
