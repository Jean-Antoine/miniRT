/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_product_vectors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:39 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:09:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector	ft_cross_product_vectors(t_vector vector1, t_vector vector2)
{
	t_vector	vector_res;

	vector_res.x = vector1.y * vector2.z - vector1.z * vector2.y;
	vector_res.y = vector1.z * vector2.x - vector1.x * vector2.z;
	vector_res.z = vector1.x * vector2.y - vector1.y * vector2.x;
	return (vector_res);
}
