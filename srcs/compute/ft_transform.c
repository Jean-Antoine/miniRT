/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:49:27 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/20 12:49:22 by jeada-si         ###   ########.fr       */
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

// int main(void)
// {
// 	t_ray	ray;
// 	t_ray	ray_transformed;


// 	ray = ft_ray(ft_point(1, 2, 3), ft_vector(0, 1, 0));
// 	ray_transformed = ft_transform(ray, ft_translation(3, 4, 5));
// 	ft_tuple_print(ray_transformed.origin);
// 	ft_tuple_print(ray_transformed.direction);
	
// 	ray_transformed = ft_transform(ray, ft_scaling(2, 3, 4));
// 	ft_tuple_print(ray_transformed.origin);
// 	ft_tuple_print(ray_transformed.direction);
// }
