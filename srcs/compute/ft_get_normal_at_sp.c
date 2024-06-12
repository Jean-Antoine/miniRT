/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_normal_at_sp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:06:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/11 18:01:57 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_vector	ft_get_normal_at_sp(t_object sphere, t_point world_point)
{
	t_point		obj_point;
	t_vector	obj_normal;
	t_vector	world_normal;

	obj_point = ft_mat_prod_tup(sphere.transform, world_point);
	obj_normal = ft_p_to_v(ft_p_set(0, 0, 0), obj_point);
	world_normal = ft_mat_prod_tup(ft_mat_trans(sphere.transform), obj_normal);
	world_normal.w = 0;
	return (ft_v_normalize(world_normal));
}
