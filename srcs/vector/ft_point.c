/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 16:56:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_point	ft_point(double x, double y, double z)
{
	t_point	point;

	point.w = 1;
	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
