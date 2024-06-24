/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:16 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:03:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	ft_v_add(t_vector vector1, t_vector vector2)
{
	t_vector	vector_res;

	vector_res.x = vector1.x + vector2.x;
	vector_res.y = vector1.y + vector2.y;
	vector_res.z = vector1.z + vector2.z;
	vector_res.w = 0;
	return (vector_res);
}

static double	ft_dmax(double x, double y)
{
	if (x < y)
		return (y);
	return (x);
}

t_color	ft_color_rescale(t_color color)
{
	double	max;

	max = ft_dmax(color.x, color.y);
	max = ft_dmax(max, color.z);
	if (max > 1)
		return (ft_v_scalar_prod(1 / max, color));
	return (color);
}

t_color	ft_color_add(t_color color1, t_color color2)
{
	return (ft_v_add(color1, color2));
}

t_color	ft_color_brightness(double brightness, t_color color)
{
	return (ft_v_scalar_prod(brightness, color));
}
