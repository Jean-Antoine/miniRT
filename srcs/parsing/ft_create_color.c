/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 18:05:31 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_color	ft_create_color(int r, int g, int b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
