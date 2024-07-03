/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:09:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/02 13:10:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static int	ft_is_inters(t_ray ray, double *t1, double *t2)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_vector	sphere_to_ray;

	sphere_to_ray = ft_p_to_v(ft_point(0, 0, 0), ray.origin);
	a = ft_v_dot_prod(ray.direction, ray.direction);
	b = 2.0 * ft_v_dot_prod(ray.direction, sphere_to_ray);
	c = ft_v_dot_prod(sphere_to_ray, sphere_to_ray) - 1.0;
	discr = b * b - 4.0 * a * c;
	if (discr < 0)
		return (FALSE);
	*t1 = (-b - sqrt(discr)) / (2.0 * a);
	*t2 = (-b + sqrt(discr)) / (2.0 * a);
	return (TRUE);
}

static int	ft_inters_sp(t_object *sphere, t_ray *ray)
{
	t_ray		ray2;
	double		t1;
	double		t2;

	ray2 = ft_transform(*ray, sphere->transform);
	if (ft_is_inters(ray2, &t1, &t2) == FALSE)
		return (EXIT_SUCCESS);
	return (
		ft_new_inters(ray, sphere, t1) ||
		ft_new_inters(ray, sphere, t2));
}

static int	ft_inters_pl(t_object *plane, t_ray *ray)
{
	t_ray		ray2;
	double		t;

	ray2 = ft_transform(*ray, plane->transform);
	if (ft_eq(ray2.direction.y, 0))
		return (EXIT_FAILURE);
	t = -ray2.origin.y / ray2.direction.y;
	return (ft_new_inters(ray, plane, t));
}

int	ft_inters(t_scene scene, t_ray *ray)
{
	t_object	*object;

	object = scene.objects;
	while (object)
	{
		if (object->type == sphere)
			ft_inters_sp(object, ray); // check failure ?
		else if (object->type == plane)
			ft_inters_pl(object, ray);
		else if (object->type == cylinder)
			ft_inters_cyl(object, ray);
		object = object->next;
	}
	return (EXIT_SUCCESS);
}
