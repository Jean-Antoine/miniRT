/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bump_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:28:06 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 14:28:30 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_vector	ft_get_bump_normal(t_object *object, t_point uv,
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
	map_color = ft_get_uv_color_img(object->material.texture, uv.x, uv.y);
	map_color = ft_v_add(ft_v_scalar_prod(2, map_color), ft_vector(-1, -1, -1));
	normal = ft_tup_prod_mat(tbn, map_color);
	return (ft_v_normalize(normal));
}
