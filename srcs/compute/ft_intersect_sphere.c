/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:24:51 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/31 18:21:58 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

double	ft_get_discriminant(t_object sphere, t_ray ray, double *t1, double *t2)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_vector	sphere_to_ray;

	//sphere_to_ray ← ray.origin - point(0, 0, 0) ? pour l'instant spher de rayon 1
	sphere_to_ray = ft_p_to_v(sphere.position, ray.origin);
	a = ft_v_dot_prod(ray.direction, ray.direction);
	b = 2 * ft_v_dot_prod(ray.direction, sphere_to_ray);
	c = ft_v_dot_prod(sphere_to_ray, sphere_to_ray) - 1;
	*t1 = 0;
	*t2 = 0;
	discr = exp2(b) - 4 * a * c;
	if (discr < 0)
		return (discr);
	*t1 = (-b - sqrt(discr)) / 2 * a;
	*t2 = (-b + sqrt(discr)) / 2 * a;
	return (discr);
}

t_inters	*ft_create_intersection(t_object *object, double t)
{
	t_inters	*inters;

	inters = ft_calloc(1, sizeof(t_inters));
	if (!inters)
	{
		ft_error("ft_create_intersection", TRUE);
		return (NULL);
	}
	inters->object = object;
	inters->t = t;
	return (inters);
}

void	ft_insters_addback(t_inters **lst, t_inters *new)
{
	t_inters	*inters;

	if (!lst)
		return ;
	inters = *lst;
	if (!inters)
	{
		*lst = new;
		return ;
	}
	while (inters->next)
		inters = inters->next;
	inters->next = new;
}

int	ft_intersect_sphere(t_inters **inters_lst, t_object *sphere, t_ray ray)
{
	t_inters	*inters1;
	t_inters	*inters2;
	double		discriminant;
	double		t1;
	double		t2;

	discriminant = ft_get_discriminant(*sphere, ray, &t1, &t2);
	if (discriminant < 0)
		return (EXIT_SUCCESS);
	inters1 = ft_create_intersection(sphere, t1);
	if (!inters1)
		return (EXIT_FAILURE);
	ft_insters_addback(inters_lst, inters1);
	inters2 = ft_create_intersection(sphere, t2);
	if (!inters2)
		return (EXIT_FAILURE);
	ft_insters_addback(inters_lst, inters2);
	return (EXIT_SUCCESS);
}
