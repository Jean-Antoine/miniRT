/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_mat_obj.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lpaquatt <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/10 12:44:24 by jeada-si		  #+#	#+#			 */
/*   Updated: 2024/07/01 14:06:04 by lpaquatt		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "compute.h"

static void	ft_mat_sp(t_object *sphere)
{
	sphere->transform = ft_mat_prod(
			sphere->transform,
			ft_translation(
				sphere->position.x, sphere->position.y, sphere->position.z));
	sphere->transform = ft_mat_prod(
			sphere->transform,
			ft_scaling(sphere->diameter / 2.0, sphere->diameter / 2.0,
				sphere->diameter / 2.0));
	sphere->transform = ft_mat_inv(sphere->transform);
}

static void	ft_mat_pl(t_object *plane)
{
	double	theta_x;
	double	theta_z;
	t_mat	rotation;
	t_mat	translation;

	translation = ft_translation(plane->position.x, plane->position.y,
			plane->position.z);
	theta_x = atan2(plane->direction.z,
			sqrt(pow(plane->direction.x, 2) + pow(plane->direction.y, 2)));
	theta_z = atan2(plane->direction.x, plane->direction.y);
	rotation = ft_mat_prod(ft_rotation_x(theta_x), ft_rotation_z(theta_z));
	plane->transform = ft_mat_prod(translation, rotation);
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
