/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/03 23:41:36 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_color	ft_int_to_color(unsigned int color) // deja defini ailleurs ..?
{
	t_color	rgb;

	rgb.x = (color >> 16) & 0xFF;
	rgb.y = (color >> 8) & 0xFF;
	rgb.z = color & 0xFF;
	return (rgb);
}

unsigned int	ft_get_color_from_img(t_img img, int x, int y)
{
	char	*color;
	int		offset;

	offset = (img.line_len * y) + (x * (img.bits_per_pixel / 8));
	color = img.img_buff + offset;
	return (*((unsigned int *)color));
}

t_color	ft_get_uv_color_at(t_img texture, double u, double v)
{
	int		color;

	u *= texture.width;
	v *= texture.height;
	color = ft_get_color_from_img(texture, u, v);
	return (ft_int_to_color(color));
}

static t_vector	ft_get_bump_normal_sp(t_object *sphere, t_point point, t_vector normal)
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
	map_color = ft_get_uv_color_at(sphere->material.texture, uv.x, uv.y);
	map_color = ft_v_add(ft_v_scalar_prod(2, map_color), ft_vector(-1, -1, -1));
	normal = ft_mat_prod_tup(tbn, map_color);
	return (ft_v_normalize(normal));
}


static t_vector	ft_normal_at_sp(t_object *sphere, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;

	obj_point = ft_mat_prod_tup(sphere->transform, world_point);
	obj_normal = ft_p_to_v(ft_point(0, 0, 0), obj_point);
	if (sphere->material.texture.path)
		return (ft_get_bump_normal_sp(sphere, obj_point, obj_normal));
	world_normal = ft_mat_prod_tup(ft_mat_trans(sphere->transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}

static t_vector	ft_normal_at_cyl(t_object *cyl, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;
	double		dist;

	obj_point = ft_mat_prod_tup(cyl->transform, world_point);
	dist = pow(obj_point.x, 2) +  pow(obj_point.z, 2);
	if (dist < 1.0 && obj_point.y >= (0.5 - 0.001))
		obj_normal = ft_vector(0, 1, 0);
	else if (dist < 1.0 && obj_point.y <= (-0.5 + 0.001))
		obj_normal = ft_vector(0, -1, 0);
	else
		obj_normal = ft_vector(obj_point.x, 0, obj_point.z);
	world_normal = ft_mat_prod_tup(ft_mat_trans(cyl->transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}

t_vector	ft_normal_at(t_object *object, t_point point)
{
	if (object->type == sphere)
		return (ft_normal_at_sp(object, point));
	else if (object->type == plane)
		return (object->direction);
	else if (object->type == cylinder)
		return (ft_normal_at_cyl(object, point));
	return (ft_vector(0, 0, 0));
}
