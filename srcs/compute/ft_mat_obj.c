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

static t_mat	ft_rotation(t_vector vector)
{
	double	theta_x;
	double	theta_z;

	theta_x = atan2(vector.z, sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
	theta_z = atan2(vector.x, vector.y);
	return (ft_mat_prod(ft_rotation_x(theta_x), ft_rotation_z(theta_z)));
}

static void	ft_mat_pl(t_object *plane)
{
	t_mat	rotation;
	t_mat	translation;

	translation = ft_translation(plane->position.x, plane->position.y,
			plane->position.z);
	rotation = ft_rotation(plane->direction);
	plane->transform = ft_mat_prod(translation, rotation);
	plane->transform = ft_mat_inv(plane->transform);
}

static void ft_mat_cyl(t_object *cyl)
{	
	cyl->transform = ft_mat_prod(
		cyl->transform,
		ft_rotation(cyl->direction)
	);
	cyl->transform = ft_mat_prod(
		cyl->transform,
		ft_scaling(cyl->diameter / 2.0, cyl->height, cyl->diameter / 2.0)
	);
	cyl->transform = ft_mat_prod(
		cyl->transform,
		ft_translation(cyl->position.x, cyl->position.y, cyl->position.z)
	);	
	// ft_mat_print(ft_rotation(cyl->direction));
	// ft_mat_print(cyl->transform);
	cyl->transform = ft_mat_inv(cyl->transform);
}

void	ft_mat_obj(t_object *list)
{
	while (list)
	{
		if (list->type == sphere)
			ft_mat_sp(list);
		else if (list->type == plane)
			ft_mat_pl(list);
		else if (list->type == cylinder)
			ft_mat_cyl(list);
		list = list->next;
	}
}
