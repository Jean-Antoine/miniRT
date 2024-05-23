/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:18 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:04:21 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vector	ft_normalize_vector(t_vector vector)
{
	return (ft_multiply_vector_by_num(1 / ft_get_vector_norm(vector), vector));
}
