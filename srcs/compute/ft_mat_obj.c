/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:44:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/25 16:47:41 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_mat_sphere_to_plan_test(t_object *sphere) //
{
	sphere->transform = ft_mat_prod(
			sphere->transform,
			ft_scaling(1000, 0.01, 1000));
	sphere->transform = ft_mat_prod(
			sphere->transform,
			ft_translation(
				sphere->position.x, sphere->position.y, sphere->position.z));
	sphere->transform = ft_mat_inv(sphere->transform);
}

void	ft_mat_obj(t_object *list)
{
	while (list)
	{
		if (list->type == sphere)
			ft_mat_sphere(list);
		if (!list->next) //last sphere -> plan : x = 0
			ft_mat_sphere_to_plan_test(list);
		list = list->next;
	}
}
