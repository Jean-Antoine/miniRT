/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_to_v.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:44 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:13:15 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

// vector = end_point - starting_point
t_vector	ft_p_to_v(t_point starting_point,
	t_point end_point)
{
	t_vector	vector;

	vector.x = end_point.x - starting_point.x;
	vector.y = end_point.y - starting_point.y;
	vector.z = end_point.z - starting_point.z;
	vector.w = 0;
	return (vector);
}
