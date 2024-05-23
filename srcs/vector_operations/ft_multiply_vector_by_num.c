/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply_vector_by_num.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:04:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector	ft_multiply_vector_by_num(double factor, t_vector vector)
{
	vector.x *= factor;
	vector.y *= factor;
	vector.z *= factor;
	return (vector);
}
