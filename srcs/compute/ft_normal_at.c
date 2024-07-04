/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/04 17:48:50 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_vector	ft_normal_at_cyl(t_object *cyl, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;
	double		dist;

	obj_point = ft_mat_prod_tup(cyl->transform, world_point);
	dist = pow(obj_point.x, 2) + pow(obj_point.z, 2);
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
