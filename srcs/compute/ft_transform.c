/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:49:27 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/25 16:49:14 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_ray	ft_transform(t_ray ray, t_mat mat)
{
	t_ray	transformed_ray;

	transformed_ray.direction = ft_mat_prod_tup(mat, ray.direction);
	transformed_ray.origin = ft_mat_prod_tup(mat, ray.origin);
	return (transformed_ray);
}
