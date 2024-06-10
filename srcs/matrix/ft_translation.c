/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:45:15 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/10 14:04:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

t_mat	ft_translation(int x, int y, int z)
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
