/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_scalar_prod.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 11:00:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	ft_v_scalar_prod(double scalar, t_vector vector)
{
	vector.x *= scalar;
	vector.y *= scalar;
	vector.z *= scalar;
	return (vector);
}
