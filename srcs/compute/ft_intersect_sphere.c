/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:24:51 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/07 10:58:31 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static double	ft_get_sph_inters_values(t_ray ray, double *t1, double *t2)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_vector	sphere_to_ray;

	sphere_to_ray = ft_p_to_v(ft_p_set(0, 0, 0), ray.origin);
	a = ft_v_dot_prod(ray.direction, ray.direction);
	b = 2 * ft_v_dot_prod(ray.direction, sphere_to_ray);
	c = ft_v_dot_prod(sphere_to_ray, sphere_to_ray) - 1;
	discr = pow(b, 2) - 4 * a * c;
	if (discr < 0)
		return (discr);
	*t1 = (-b - sqrt(discr)) / (2 * a);
	*t2 = (-b + sqrt(discr)) / (2 * a);
	return (discr);
}

int	ft_intersect_sphere(t_object *sphere, t_ray *ray)
{
	t_ray		ray2;
	double		discriminant;
	double		t1;
	double		t2;

	ray2 = ft_transform(*ray, ft_mat_inv(sphere->transform));
	discriminant = ft_get_sph_inters_values(ray2, &t1, &t2);
	if (discriminant < 0)
		return (EXIT_SUCCESS);
	if (ft_new_insters_addback(&ray->inters_lst, sphere, t1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ft_new_insters_addback(&ray->inters_lst, sphere, t2) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
