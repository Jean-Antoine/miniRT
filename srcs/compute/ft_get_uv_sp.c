/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uv_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:13:00 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/03 18:22:26 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

// get (u,v) coordinates for a point on a unit sphere
t_point	ft_get_uv_sp(t_point point)
{
	t_point	uv;
	double	theta;
	double	phi;

	ft_bzero(&uv, sizeof(t_point));
	theta = atan2(point.x, point.z);
	phi = acos(point.y);
	uv.x = 1 - (theta / (2 * M_PI) + 0.5);
	uv.y = 1 - phi / M_PI;
	return (uv);
}
