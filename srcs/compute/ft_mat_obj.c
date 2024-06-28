/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:44:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/28 18:13:53 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"


// vecteur unitaire = (0,1,0)


void	ft_mat_pl(t_object *plane)
{
 	double theta_x, theta_y;
    t_mat rotation_x, rotation_y,  combined_rotation, translation;

    // Calculate rotation angles
    theta_x = atan2(sqrt(pow(plane->direction.x, 2) + pow(plane->direction.z, 2)), plane->direction.y);
    theta_y = atan2(plane->direction.x, plane->direction.z);

    // Create rotation matrices
    rotation_x = ft_rotation_x(theta_x);
    rotation_y = ft_rotation_y(theta_y);
    combined_rotation = ft_mat_prod(rotation_x, rotation_y);

    // Create translation matrices
    translation = ft_translation(plane->position.x, plane->position.y, plane->position.z);

    // Apply transformation and invert
	plane->transform = ft_mat_prod(combined_rotation, translation);
    plane->transform = ft_mat_inv(plane->transform);

    // Print the transformation matrix
    ft_mat_print(plane->transform);
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
