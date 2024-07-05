/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:01:18 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/03 15:27:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_mat	ft_rotation_x(double r)
{
	t_mat	mat;

	mat = ft_mat_id(4);
	mat.mat[1][1] = cos(r);
	mat.mat[2][2] = cos(r);
	mat.mat[1][2] = -sin(r);
	mat.mat[2][1] = sin(r);
	return (mat);
}

static t_mat	ft_rotation_y(double r)
{
	t_mat	mat;

	mat = ft_mat_id(4);
	mat.mat[0][0] = cos(r);
	mat.mat[2][2] = cos(r);
	mat.mat[2][0] = -sin(r);
	mat.mat[0][2] = sin(r);
	return (mat);
}

static t_mat	ft_rotation_z(double r)
{
	t_mat	mat;

	mat = ft_mat_id(4);
	mat.mat[1][1] = cos(r);
	mat.mat[0][0] = cos(r);
	mat.mat[0][1] = -sin(r);
	mat.mat[1][0] = sin(r);
	return (mat);
}

t_mat	ft_rotate_x(t_mat matrix, double r)
{	return (
		ft_mat_prod(
			matrix,
			ft_rotation_x(r)
		)
	);
}

t_mat	ft_rotate_y(t_mat matrix, double r)
{	return (
		ft_mat_prod(
			matrix,
			ft_rotation_y(r)
		)
	);
}

t_mat	ft_rotate_z(t_mat matrix, double r)
{	return (
		ft_mat_prod(
			matrix,
			ft_rotation_z(r)
		)
	);
}
