/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:25:29 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/05 15:26:25 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

//Scenario: Creating and querying a ray
t_ray	*ft_create_ray(t_point origin, t_vector direction)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
	{
		ft_error("ft_create_ray", TRUE);
		return (NULL);
	}
	ray->origin = origin;
	ray->direction = direction;
	return (ray);
}
