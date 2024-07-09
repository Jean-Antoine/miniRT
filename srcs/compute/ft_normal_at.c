/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 14:28:00 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_vector	ft_normal_at_sp(t_point obj_point, t_object *sphere)
{
	t_vector	obj_normal;

	obj_normal = ft_p_to_v(ft_point(0, 0, 0), obj_point);
	if (sphere->material.texture.path)
		obj_normal = ft_get_bump_normal(sphere,
				ft_get_uv_sp(obj_point), obj_normal);
	return (obj_normal);
}

static t_vector	ft_normal_at_cyl(t_point obj_point, t_object *cylinder)
{
	t_vector	obj_normal;
	double		dist;

	dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
	if (dist < 1.0 && obj_point.y >= (0.5 - 0.001))
		obj_normal = ft_vector(0, 1, 0);
	else if (dist < 1.0 && obj_point.y <= (-0.5 + 0.001))
		obj_normal = ft_vector(0, -1, 0);
	else
		obj_normal = ft_vector(obj_point.x, 0, obj_point.z);
	if (cylinder->material.texture.path)
		obj_normal = ft_get_bump_normal(cylinder,
				ft_get_uv_cy(obj_point), obj_normal);
	return (obj_normal);
}

static t_vector	ft_normal_at_cone(t_point obj_point, t_object *cone)
{
	t_vector	obj_normal;
	double		dist;
	double		y;

	dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
	y = sqrt(dist);
	if (obj_point.y > 0)
		y = -y;
	if (dist < 1.0 && obj_point.y >= (0.5 - 0.001))
		obj_normal = ft_vector(0, 1, 0);
	else if (dist < 1.0 && obj_point.y <= (-0.5 + 0.001))
		obj_normal = ft_vector(0, -1, 0);
	else
		obj_normal = ft_vector(obj_point.x, y, obj_point.z);
	if (cone->material.texture.path)
		obj_normal = ft_get_bump_normal(cone,
				ft_get_uv_cone(obj_point), obj_normal);
	return (obj_normal);
}

t_vector	ft_normal_at_pl(t_point obj_point, t_object *plane)
{
	t_point		uv;

	if (!plane->material.texture.path)
		return (ft_vector(0, 1, 0));
	obj_point = ft_v_scalar_prod(0.5, obj_point);
	uv = ft_point(obj_point.x - floor(obj_point.x),
			obj_point.z - floor(obj_point.z), 0);
	return (ft_get_bump_normal(plane, uv, ft_vector(0, 1, 0)));
}

t_vector	ft_normal_at(t_object *object, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;

	obj_normal = ft_vector(0, 0, 0);
	obj_point = ft_mat_prod_tup(object->transform, world_point);
	if (object->type == plane)
		obj_normal = ft_normal_at_pl(obj_point, object);
	else if (object->type == sphere)
		obj_normal = ft_normal_at_sp(obj_point, object);
	else if (object->type == cylinder)
		obj_normal = ft_normal_at_cyl(obj_point, object);
	else if (object->type == cone)
		obj_normal = ft_normal_at_cone(obj_point, object);
	world_normal = ft_mat_prod_tup(ft_mat_trans(object->transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}
