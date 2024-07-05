/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:01:18 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/05 17:00:08 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_rotation_x(double r)
{
	t_mat	mat;

	mat = ft_mat_id(4);
	mat.mat[1][1] = cos(r);
	mat.mat[2][2] = cos(r);
	mat.mat[1][2] = -sin(r);
	mat.mat[2][1] = sin(r);
	return (mat);
}

t_mat	ft_rotation_y(double r)
{
	t_mat	mat;

	mat = ft_mat_id(4);
	mat.mat[0][0] = cos(r);
	mat.mat[2][2] = cos(r);
	mat.mat[2][0] = -sin(r);
	mat.mat[0][2] = sin(r);
	return (mat);
}

t_mat	ft_rotation_z(double r)
{
	t_mat	mat;

	mat = ft_mat_id(4);
	mat.mat[1][1] = cos(r);
	mat.mat[0][0] = cos(r);
	mat.mat[0][1] = -sin(r);
	mat.mat[1][0] = sin(r);
	return (mat);
}
