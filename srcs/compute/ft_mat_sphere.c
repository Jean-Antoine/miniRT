/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:24:08 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/26 13:17:24 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_mat_sphere(t_object *sphere)
{
	sphere->transform = ft_mat_prod(
			sphere->transform,
			ft_translation(
				sphere->position.x, sphere->position.y, sphere->position.z));
	sphere->transform = ft_mat_prod(
			sphere->transform,
			ft_scaling(sphere->diameter / 2.0, sphere->diameter / 2.0,
				sphere->diameter / 2.0));
	sphere->transform = ft_mat_inv(sphere->transform);
}
