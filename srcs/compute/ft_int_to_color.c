/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:46:35 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 14:57:35 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static double	ft_dmin(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

t_color	ft_int_to_color(unsigned int color)
{
	t_color		rgb;

	rgb.x = ((color >> 16) & 0xFF) / 255.0;
	rgb.y = ((color >> 8) & 0xFF) / 255.0;
	rgb.z = ((color) & 0xFF) / 255.0;
	rgb.w = 0;
	return (rgb);
}

int	ft_color_to_int(t_color color)
{	
	return (((int)(ft_dmin(color.x * 255.0, 255)) << 16)
		+ ((int)(ft_dmin(color.y * 255.0, 255)) << 8)
		+ (int)(ft_dmin(color.z * 255.0, 255)));
}
