/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_discriminant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:00:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/05 12:26:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static void	ft_discr_sp(t_ray *ray, t_discr *discr)
{
	t_vector	sphere_to_ray;

	sphere_to_ray = ft_p_to_v(ft_point(0, 0, 0), ray->origin);
	discr->a = ft_v_dot_prod(ray->direction, ray->direction);
	discr->b = 2.0 * ft_v_dot_prod(ray->direction, sphere_to_ray);
	discr->c = ft_v_dot_prod(sphere_to_ray, sphere_to_ray) - 1.0;
	discr->d = discr->b * discr->b - 4.0 * discr->a * discr->c;
	if (discr->d > 0)
		discr->n = 2;
}

static void	ft_discr_cy(t_ray *ray, t_discr *discr)
{
	discr->a = pow(ray->direction.x, 2) + pow(ray->direction.z, 2);
	if (ft_eq(discr->a, TOLERANCE))
		return ;
	discr->b = 2.0 * ray->origin.x * ray->direction.x
		+ 2.0 * ray->origin.z * ray->direction.z;
	discr->c = ray->origin.x * ray->origin.x + pow(ray->origin.z, 2) - 1.0;
	discr->d = discr->b * discr->b - 4.0 * discr->a * discr->c;
	if (discr->d > 0)
		discr->n = 2;
}

static void	ft_discr_co(t_ray *ray, t_discr *discr)
{
	t_tuple	d;
	t_tuple	o;

	d = ray->direction;
	o = ray->origin;
	discr->a = pow(d.x, 2) - pow(d.y, 2) + pow(d.z, 2);
	discr->b = 2.0 * o.x * d.x - 2.0 * o.y * d.y + 2.0 * o.z * d.z;
	discr->c = pow(o.x, 2) - pow(o.y, 2) + pow(o.z, 2);
	if (ft_eq(discr->a, TOLERANCE))
	{
		if (!ft_eq(discr->b, TOLERANCE))
			discr->n = 1;
		return ;
	}
	discr->d = discr->b * discr->b - 4.0 * discr->a * discr->c;
	if (discr->d > 0)
		discr->n = 2;
}

static int	ft_truncate(t_ray *ray, t_object *object, double t)
{
	double	y;

	if (object->type == sphere)
		return (TRUE);
	y = ft_position(*ray, t).y;
	if (object->type == cone && y > -0.5 && y < 0.0)
		return (TRUE);
	if (object->type == cylinder && y > -0.5 && y < 0.5)
		return (TRUE);
	return (FALSE);
}

t_discr	ft_discriminant(t_object *object, t_ray *ray)
{
	t_discr	discr;

	discr.n = 0;
	if (object->type == sphere)
		ft_discr_sp(ray, &discr);
	else if (object->type == cone)
		ft_discr_co(ray, &discr);
	else if (object->type == cylinder)
		ft_discr_cy(ray, &discr);
	if (discr.n == 1)
		discr.t0 = -discr.c / (2.0 * discr.b);
	else if (discr.n == 2)
	{
		discr.t0 = (-discr.b - sqrt(discr.d)) / (2.0 * discr.a);
		discr.t1 = (-discr.b - sqrt(discr.d)) / (2.0 * discr.a);
		(discr.t0) *= ft_truncate(ray, object, discr.t0);
		(discr.t1) *= ft_truncate(ray, object, discr.t1);
	}
	return (discr);
}
