/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normal_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/04 17:48:50 by lpaquatt         ###   ########.fr       */
=======
/*   Updated: 2024/07/04 15:42:36 by jeada-si         ###   ########.fr       */
>>>>>>> 46b5a25 (cone cyl)
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_vector	ft_normal_at_sp(t_point obj_point)
{
	return (ft_p_to_v(ft_point(0, 0, 0), obj_point));
}

static t_vector	ft_normal_at_cyl(t_point obj_point)
{
	double	dist;
	
	dist = pow(obj_point.x, 2) +  pow(obj_point.z, 2);
	if (dist < 1.0 && obj_point.y >= (0.5 - 0.001))
		return(ft_vector(0, 1, 0));
	else if (dist < 1.0 && obj_point.y <= (-0.5 + 0.001))
		return(ft_vector(0, -1, 0));
	else
		return(ft_vector(obj_point.x, 0, obj_point.z));
}

static t_vector	ft_normal_at_cone(t_point obj_point)
{
	double	dist;
	double	y;
	
	dist = pow(obj_point.x, 2) +  pow(obj_point.z, 2);
	y = sqrt(dist);
	if (obj_point.y > 0)
		y = -y;
	if (dist < 1.0 && obj_point.y >= (0.5 - 0.001))
		return(ft_vector(0, 1, 0));
	else if (dist < 1.0 && obj_point.y <= (-0.5 + 0.001))
		return(ft_vector(0, -1, 0));
	else
		return(ft_vector(obj_point.x, y, obj_point.z));
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
		obj_normal = ft_normal_at_sp(obj_point);
	else if (object->type == cylinder)
		obj_normal = ft_normal_at_cyl(obj_point);
	else if (object->type == cone)
		obj_normal = ft_normal_at_cone(obj_point);
	world_normal = ft_mat_prod_tup(ft_mat_trans(object->transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}
