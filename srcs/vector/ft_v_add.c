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
	vector_res.z = 0;
	return (vector_res);
}
