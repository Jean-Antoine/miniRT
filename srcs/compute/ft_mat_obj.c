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
	sphere->transform = ft_translate(sphere->transform, sphere->position);
	sphere->transform = ft_scale(sphere->transform,
		sphere->diameter / 2, sphere->diameter / 2, sphere->diameter / 2);
	sphere->transform = ft_mat_inv(sphere->transform);
}

static t_mat	ft_rotate(t_mat mat, t_vector vector)
{
	double	theta_x;
	double	theta_z;

	theta_x = atan2(vector.z, sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
	theta_z = atan2(vector.x, vector.y);
	mat = ft_rotate_z(mat, theta_z);
	mat = ft_rotate_x(mat, theta_x);	
	return (mat);
}

static void	ft_mat_pl(t_object *plane)
{
	plane->transform = ft_translate(plane->transform, plane->position);
	plane->transform = ft_rotate(plane->transform, plane->direction);
	plane->transform = ft_mat_inv(plane->transform);
}

static void ft_mat_cyl(t_object *cyl)
{
	cyl->transform = ft_translate(cyl->transform, cyl->position);
	cyl->transform = ft_translate(cyl->transform, 
		ft_v_scalar_prod(cyl->height / 2, cyl->direction));
	cyl->transform = ft_rotate(cyl->transform, cyl->direction);
	cyl->transform = ft_scale(cyl->transform, 
		cyl->diameter / 2.0, cyl->height, cyl->diameter / 2.0);	
	cyl->transform = ft_mat_inv(cyl->transform);
}

static void ft_mat_cone(t_object *cone)
{
	cone->transform = ft_translate(cone->transform, cone->position);
	cone->transform = ft_translate(cone->transform,
		ft_v_scalar_prod(cone->height, cone->direction));
	cone->transform = ft_rotate(cone->transform, cone->direction);
	cone->transform = ft_scale(cone->transform, 
		cone->diameter, cone->height * 2, cone->diameter);	
	cone->transform = ft_mat_inv(cone->transform);
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
		else if (list->type == cone)
			ft_mat_cone(list);
		list = list->next;
	}
}
