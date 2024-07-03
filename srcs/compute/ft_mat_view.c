/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:06:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/03 14:07:07 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_mat	ft_mat_view(t_vector forward, t_vector left, t_vector up,
	t_point origin)
{
	t_mat	view;

	view = ft_matrix(4, 4);
	view.mat[0][0] = left.x;
	view.mat[0][1] = left.y;
	view.mat[0][2] = left.z;
	view.mat[1][0] = up.x;
	view.mat[1][1] = up.y;
	view.mat[1][2] = up.z;
	view.mat[2][0] = forward.x;
	view.mat[2][1] = forward.y;
	view.mat[2][2] = forward.z;
	view.mat[3][0] = origin.x;
	view.mat[3][1] = origin.y;
	view.mat[3][2] = origin.z;
	view.mat[3][3] = 1;
	return (view);
}
