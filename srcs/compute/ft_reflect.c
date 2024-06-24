/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:52:46 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/24 14:16:22 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"


t_vector	ft_reflect(t_vector light, t_vector normal)
{
	t_vector	reflection;

	reflection = ft_v_scalar_prod(-2 * ft_v_dot_prod(light, normal), normal);
	reflection = ft_v_add(light, reflection);
	return (reflection);
}

// int main(void)
// {
// 	ft_tuple_print(
// 		ft_reflect(
// 			ft_vector(1, -1, 0),
// 			ft_vector(0, 1, 0)
// 		)
// 	);
// 	ft_tuple_print(
// 		ft_reflect(
// 			ft_vector(0, -1, 0),
// 			ft_vector(sqrt(2)/2, sqrt(2)/2, 0)
// 		)
// 	);
// }
