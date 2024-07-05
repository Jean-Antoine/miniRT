/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters_cyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:15:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/05 11:40:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"


static int	ft_add_inters_c(t_ray *ray, t_ray *dest, t_object *object, double t)
{
	double	y;

	y = ft_position(*ray, t).y;
	if (object->type == cone && y > -0.5 && y < 0.0)
		return (ft_add_inters(dest, object, t));
	if (object->type == cylinder && y > -0.5 && y < 0.5)
		return (ft_add_inters(dest, object, t));
	return (EXIT_SUCCESS);
}

static int	ft_check_cap(t_ray *ray, double t, t_bool is_cone)
{
	t_point	point;

	point = ft_position(*ray, t);
	if (!is_cone)
		return (pow(point.x, 2) + pow(point.z, 2) <= 1);
	return (pow(point.x, 2) + pow(point.z, 2) <= pow(0.5, 2));
}

static int	ft_add_cap_inters(
	t_ray *ray,
	t_ray *dest,
	t_object *cyl,
	double cap)
{
	double	t;

	if (ft_eq(ray->direction.y, TOLERANCE))
		return (EXIT_SUCCESS);
	t = (cap - ray->origin.y) / ray->direction.y;
	if (ft_check_cap(ray, t, cyl->type == cone))
		return (ft_add_inters(dest, cyl, t));
	return (EXIT_SUCCESS);
}

int	ft_inters_cyl(t_object *object, t_ray *ray, t_ray *dest)
{
	t_discr	disc;

	if (object->type == cylinder && 
		(ft_add_cap_inters(ray, dest, object, -0.5)
		|| ft_add_cap_inters(ray, dest, object, 0.5)))
		return (EXIT_FAILURE);
	if (object->type == cone
		&& ft_add_cap_inters(ray, dest, object, -0.5))
		return (EXIT_FAILURE);
	if (object->type == cylinder && !ft_disc_cyl(ray, &disc))
		return (EXIT_SUCCESS);
	if (object->type == cone && !ft_disc_cone(ray, &disc))
		return (EXIT_SUCCESS);
	if (disc.n == 1)
		return (ft_add_inters_c(ray, dest, object,
			-disc.c / (2.0 * disc.b)));
	return (
		ft_add_inters_c(ray, dest, object,
			(-disc.b - sqrt(disc.d)) / (2.0 * disc.a))
		|| ft_add_inters_c(ray, dest, object,
			(-disc.b + sqrt(disc.d)) / (2.0 * disc.a))
	);
}
