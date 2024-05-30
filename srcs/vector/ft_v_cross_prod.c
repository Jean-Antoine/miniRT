/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_cross_prod.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:39 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:09:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	ft_v_cross_prod(t_vector vector1, t_vector vector2)
{
	t_vector	vector_res;

	vector_res.x = vector1.y * vector2.z - vector1.z * vector2.y;
	vector_res.y = vector1.z * vector2.x - vector1.x * vector2.z;
	vector_res.z = vector1.x * vector2.y - vector1.y * vector2.x;
	vector_res.w = 0;
	return (vector_res);
}
