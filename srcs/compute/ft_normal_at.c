/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 18:18:27 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_vector	ft_get_bump_normal(t_object *sphere, t_point uv,
	t_vector normal)
{
	t_mat		tbn;
	t_vector	tangent;
	t_vector	bitangent;
	t_color		map_color;

	tangent = ft_v_cross_prod(normal, ft_vector(0, 1, 0));
	if (ft_v_norm(tangent) < TOLERANCE)
		tangent = ft_v_cross_prod(normal, ft_vector(0, 0, 1));
	tangent = ft_v_normalize(tangent);
	bitangent = ft_v_normalize(ft_v_cross_prod(normal, tangent));
	tbn = ft_mat_view(normal, bitangent, tangent, ft_point(0, 0, 0));
	map_color = ft_get_uv_color_img(sphere->material.texture, uv.x, uv.y);
	map_color = ft_v_add(ft_v_scalar_prod(2, map_color), ft_vector(-1, -1, -1));
	normal = ft_tup_prod_mat(tbn, map_color);
	return (ft_v_normalize(normal));
}

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

static t_vector	ft_normal_at_cone(t_point obj_point)
{
	double	dist;
	double	y;

	dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
	y = sqrt(dist);
	if (obj_point.y > 0)
		y = -y;
	if (dist < 1.0 && obj_point.y >= (0.5 - 0.001))
		return (ft_vector(0, 1, 0));
	else if (dist < 1.0 && obj_point.y <= (-0.5 + 0.001))
		return (ft_vector(0, -1, 0));
	else
		return (ft_vector(obj_point.x, y, obj_point.z));
}

t_vector	ft_normal_at(t_object *object, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;

	obj_normal = ft_vector(0, 0, 0);
	if (object->type == plane)
		return (object->direction);
	obj_point = ft_mat_prod_tup(object->transform, world_point);
	if (object->type == sphere)
		obj_normal = ft_normal_at_sp(obj_point, object);
	else if (object->type == cylinder)
		obj_normal = ft_normal_at_cyl(obj_point, object);
	else if (object->type == cone)
		obj_normal = ft_normal_at_cone(obj_point);
	world_normal = ft_mat_prod_tup(ft_mat_trans(object->transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}
