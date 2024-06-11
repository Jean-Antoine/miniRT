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

t_vector	ft_v_cross_prod(t_vector a, t_vector b)
{
	t_vector	vector_res;

	vector_res.x = a.y * b.z - a.z * b.y;
	vector_res.y = a.z * b.x - a.x * b.z;
	vector_res.z = a.x * b.y - a.y * b.x;
	vector_res.w = 0;
	return (vector_res);
}
