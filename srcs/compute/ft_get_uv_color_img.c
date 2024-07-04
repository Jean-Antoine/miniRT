/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uv_color_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:32:51 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/04 17:33:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

unsigned int	ft_get_color_from_img(t_img img, int x, int y)
{
	char	*color;
	int		offset;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= img.width)
		x = img.width - 1;
	if (y >= img.height)
		y = img.height - 1;
	offset = (img.line_len * y) + (x * (img.bits_per_pixel / 8));
	color = img.img_buff + offset;
	return (*((unsigned int *)color));
}

t_color	ft_get_uv_color_img(t_img texture, double u, double v)
{
	int		color;

	u *= texture.width;
	v *= texture.height;
	color = ft_get_color_from_img(texture, (int)round(u), (int)(round(v)));
	return (ft_int_to_color(color));
}
