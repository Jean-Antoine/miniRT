/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_transform_sp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:49:22 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/06 14:54:32 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_set_transform_sp(t_object *sphere)
{
	double	scale;
	t_mat	scale_mat;
	t_mat	transl_mat;

	scale = sphere->diameter;
	scale_mat = ft_scaling_mat(scale, scale, scale);
	transl_mat = ft_translation_mat(sphere->position.x, sphere->position.y,
			sphere->position.z);
	sphere->transform = ft_mat_prod(transl_mat, scale_mat);
}
