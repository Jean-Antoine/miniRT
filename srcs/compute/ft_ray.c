/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:25:29 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/10 14:18:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_point	ft_position(t_ray ray, double t)
{
	return (ft_p_translate(
			ray.origin,
			ft_v_scalar_prod(t, ray.direction)));
}

t_ray	ft_ray(t_point origin, t_vector direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	ray.inters_lst = NULL;
	return (ray);
}
