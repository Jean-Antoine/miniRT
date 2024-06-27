/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:44:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/27 17:48:33 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_mat_pl(t_object *plane)
{
	plane->transform = ft_mat_prod(
			plane->transform,
			ft_translation(
				plane->position.x, plane->position.y, plane->position.z));
	// plane->transform = ft_mat_prod(
	// 		plane->transform,
	// 		ft_rotation(plane->direction.x, plane->direction.y, plane->direction.z));
	// //vecteur direction doit devenir (0,1,0)
	plane->transform = ft_mat_inv(plane->transform);
}

void	ft_mat_obj(t_object *list)
{
	while (list)
	{
		if (list->type == sphere)
			ft_mat_sp(list);
		else if (list->type == plane)
			ft_mat_pl(list);
		list = list->next;
	}
}
