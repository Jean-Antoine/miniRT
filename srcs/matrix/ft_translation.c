/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:45:15 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/11 14:42:12 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

t_mat	ft_translation(double x, double y, double z)
{
	t_mat	translation;

	ft_bzero(&translation, sizeof(translation));
	translation.col = 4;
	translation.row = 4;
	translation.mat[0][0] = 1;
	translation.mat[1][1] = 1;
	translation.mat[2][2] = 1;
	translation.mat[3][3] = 1;
	translation.mat[0][3] = x;
	translation.mat[1][3] = y;
	translation.mat[2][3] = z;
	return (translation);
}
