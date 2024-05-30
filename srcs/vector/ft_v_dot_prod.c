/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_dot_prod.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:30 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:13:25 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	ft_v_dot_prod(t_vector vector1, t_vector vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y
		+ vector1.z * vector2.z);
}
