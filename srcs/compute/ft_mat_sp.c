/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:48:13 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/27 16:48:19 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_mat_sp(t_object *sphere)
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
