/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scaling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:12:34 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/10 14:03:17 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_scaling(int x, int y, int z)
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
