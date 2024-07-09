/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:09:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 14:33:26 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static int	ft_check_cap(t_ray *ray, double t, t_bool is_cone)
{
	t_point	point;

	point = ft_position(*ray, t);
	if (!is_cone)
		return (pow(point.x, 2) + pow(point.z, 2) <= 1);
	return (pow(point.x, 2) + pow(point.z, 2) <= pow(0.5, 2));
}

static int	ft_cap_inters(t_ray *ray, t_ray *dest, t_object *obj)
{
	double	t0;
	double	t1;

	if (ft_eq(ray->direction.y, TOLERANCE))
		return (EXIT_SUCCESS);
	t0 = (-0.5 - ray->origin.y) / ray->direction.y;
	t1 = (+0.5 - ray->origin.y) / ray->direction.y;
	if (ft_check_cap(ray, t0, obj->type == cone))
		if (ft_add_inters(dest, obj, t0))
			return (EXIT_FAILURE);
	if (obj->type == cone)
		return (EXIT_SUCCESS);
	if (ft_check_cap(ray, t1, FALSE))
		return (ft_add_inters(dest, obj, t1));
	return (EXIT_SUCCESS);
}

static int	ft_inters_(t_object *object, t_ray *ray, t_ray *dest)
{
	t_discr	discr;

	if ((object->type == cylinder || object->type == cone)
		&& ft_cap_inters(ray, dest, object))
		return (EXIT_FAILURE);
	discr = ft_discriminant(object, ray);
	if (discr.n == 0)
		return (EXIT_SUCCESS);
	if (discr.n > 0 && ft_add_inters(dest, object, discr.t0))
		return (EXIT_FAILURE);
	if (discr.n == 2 && ft_add_inters(dest, object, discr.t1))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_inters_pl(t_object *plane, t_ray *ray, t_ray *dest)
{
	double		t;

	if (ft_eq(ray->direction.y, TOLERANCE))
		return (EXIT_SUCCESS);
	t = -ray->origin.y / ray->direction.y;
	return (ft_add_inters(dest, plane, t));
}

int	ft_inters(t_scene *scene, t_ray *ray)
{
	t_object	*object;
	t_ray		ray_obj;

	object = scene->objects;
	while (object)
	{
		ray_obj = ft_transform(*ray, object->transform);
		if (object->type == plane)
		{
			if (ft_inters_pl(object, &ray_obj, ray))
				return (EXIT_FAILURE);
		}
		else
		{
			if (ft_inters_(object, &ray_obj, ray))
				return (EXIT_FAILURE);
		}
		object = object->next;
	}
	return (EXIT_SUCCESS);
}
