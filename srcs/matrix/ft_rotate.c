/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:46:46 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 16:48:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_rotate_x(t_mat matrix, double r)
{
	return (
		ft_mat_prod(
			matrix,
			ft_rotation_x(r)
		)
	);
}

t_mat	ft_rotate_y(t_mat matrix, double r)
{
	return (
		ft_mat_prod(
			matrix,
			ft_rotation_y(r)
		)
	);
}

t_mat	ft_rotate_z(t_mat matrix, double r)
{
	return (
		ft_mat_prod(
			matrix,
			ft_rotation_z(r)
		)
	);
}
