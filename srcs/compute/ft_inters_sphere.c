/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:24:51 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/07 10:58:31 by lpaquatt         ###   ########.fr       */
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
	b = 2 * ft_v_dot_prod(ray.direction, sphere_to_ray);
	c = ft_v_dot_prod(sphere_to_ray, sphere_to_ray) - 1;
	discr = pow(b, 2) - 4 * a * c;
	if (discr < 0)
		return (EXIT_FAILURE);
	*t1 = (-b - sqrt(discr)) / (2 * a);
	*t2 = (-b + sqrt(discr)) / (2 * a);
	return (EXIT_SUCCESS);
}

int	ft_inters_sphere(t_object *sphere, t_ray *ray)
{
	t_ray		ray2;
	double		t1;
	double		t2;

	ray2 = ft_transform(*ray, sphere->transform);
	if (ft_is_inters(ray2, &t1, &t2))
		return (EXIT_FAILURE);
	return (
		ft_new_inters(&ray->inters_lst, sphere, t1) ||
		ft_new_inters(&ray->inters_lst, sphere, t2));
}
