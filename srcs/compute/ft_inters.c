/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:09:07 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/26 15:20:06 by lpaquatt         ###   ########.fr       */
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
		return (EXIT_FAILURE);
	*t1 = (-b - sqrt(discr)) / (2.0 * a);
	*t2 = (-b + sqrt(discr)) / (2.0 * a);
	return (EXIT_SUCCESS);
}

static int	ft_inters_sphere(t_object *sphere, t_ray *ray)
{
	t_ray		ray2;
	double		t1;
	double		t2;

	ray2 = ft_transform(*ray, sphere->transform);
	if (ft_is_inters(ray2, &t1, &t2))
		return (EXIT_FAILURE);
	return (
		ft_new_inters(ray, sphere, t1) ||
		ft_new_inters(ray, sphere, t2));
}

int	ft_inters(t_scene scene, t_ray *ray)
{
	t_object	*object;

	object = scene.objects;
	while (object)
	{
		if (object->type == sphere)
			ft_inters_sphere(object, ray); // check failure ?
		object = object->next;
	}
	return (EXIT_SUCCESS);
}
