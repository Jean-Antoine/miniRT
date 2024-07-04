/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at_sp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:21:32 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/04 17:49:43 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_vector	ft_get_bump_normal_sp(t_object *sphere, t_point point,
	t_vector normal)
{
	t_point		uv;
	t_mat		tbn;
	t_vector	tangent;
	t_vector	bitangent;
	t_color		map_color;

	uv = ft_get_uv_sp(point);
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

t_vector	ft_normal_at_sp(t_object *sphere, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;

	obj_point = ft_mat_prod_tup(sphere->transform, world_point);
	obj_normal = ft_p_to_v(ft_point(0, 0, 0), obj_point);
	if (sphere->material.texture.path)
		obj_normal = ft_get_bump_normal_sp(sphere, obj_point, obj_normal);
	world_normal = ft_mat_prod_tup(ft_mat_trans(sphere->transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}
