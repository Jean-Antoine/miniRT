/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/02 17:24:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_vector	ft_normal_at_sp(t_object *sphere, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;

	obj_point = ft_mat_prod_tup(sphere->transform, world_point);
	obj_normal = ft_p_to_v(ft_point(0, 0, 0), obj_point);
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

// int main(void)
// {
// 	t_object sp;
// 	t_vector vector;

// 	sp.type = sphere;
// 	sp.transform = ft_mat_inv(ft_translation(0, 1, 0));
// 	vector = ft_normal_at(sp, ft_point(0, 1.70711, -0.70711));
// 	ft_tuple_print(vector);

// 	sp.transform = ft_mat_inv(ft_mat_prod(ft_scaling(1, 0.5, 1), ft_rotation_z(M_PI/5)));
// 	vector = ft_normal_at(sp, ft_point(0, sqrt(2)/2, -sqrt(2)/2));
// 	ft_tuple_print(vector);
// }
