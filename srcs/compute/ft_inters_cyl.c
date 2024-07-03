/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters_cyl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:15:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/02 17:22:48 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static int	ft_is_inters(t_ray *ray, t_disc *disc)
{
	disc->a = pow(ray->direction.x, 2) + pow(ray->direction.z, 2);
	if (ft_eq(disc->a, 0))
		return (FALSE); 
	disc->b = 2.0 * ray->origin.x * ray->direction.x
		+ 2.0 * ray->origin.z *  ray->direction.z;
	disc->c = ray->origin.x * ray->origin.x + pow(ray->origin.z, 2) - 1.0;
	disc->d = disc->b * disc->b - 4.0 * disc->a * disc->c;
	if(disc->d < 0)
		return (FALSE);
	return (TRUE);
}

static int	ft_add_cyl_inters(t_ray ray, t_ray *dest, t_object *cyl, double t)
{
	double	y;

	y = ft_position(ray, t).y;
	if (y > -0.5 && y < 0.5)
		return (ft_new_inters(dest, cyl, t));
	return (EXIT_SUCCESS);
}

static int	ft_check_cap(t_ray ray, double t)
{
	t_point	point;

	point = ft_position(ray, t);
	return (pow(point.x, 2) + pow(point.z, 2) <= 1.0);
}

static int	ft_add_cap_inters(t_ray ray, t_ray *dest, t_object *cyl, double cap)
{
	double	t;
	
	if (ft_eq(ray.direction.y, 0))
		return (EXIT_SUCCESS);
	t = (cap - ray.origin.y) / ray.direction.y;
	if (ft_check_cap(ray, t))
		return (ft_new_inters(dest, cyl, t));
	return (EXIT_SUCCESS);
}

int	ft_inters_cyl(t_object *cyl, t_ray *ray)
{
	t_disc	disc;
	t_ray	ray2;

	ray2 = ft_transform(*ray, cyl->transform);
	if (ft_add_cap_inters(ray2, ray, cyl, -0.5)
		|| ft_add_cap_inters(ray2, ray, cyl, 0.5))
		return (EXIT_FAILURE);
	if (!ft_is_inters(&ray2, &disc))
		return (EXIT_SUCCESS);
	return (
		ft_add_cyl_inters(ray2, ray, cyl, (-disc.b - sqrt(disc.d)) / (2.0 * disc.a))
		|| ft_add_cyl_inters(ray2, ray, cyl, (-disc.b + sqrt(disc.d)) / (2.0 * disc.a))
	);
}
