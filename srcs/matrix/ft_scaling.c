/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scaling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:12:34 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/11 14:42:23 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_scaling(double x, double y, double z)
{
	t_mat	scaling;

	ft_bzero(&scaling, sizeof(scaling));
	scaling.col = 4;
	scaling.row = 4;
	scaling.mat[0][0] = x;
	scaling.mat[1][1] = y;
	scaling.mat[2][2] = z;
	scaling.mat[3][3] = 1;
	return (scaling);
}
