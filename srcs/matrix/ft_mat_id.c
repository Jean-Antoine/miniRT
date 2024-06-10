/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:27:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/10 14:07:16 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_mat_id(int size)
{
	t_mat	mat;
	int		i;

	mat.col = size;
	mat.row = size;
	ft_bzero(&mat.mat, sizeof(mat.mat));
	i = -1;
	while (++i < size)
		mat.mat[i][i] = 1;
	return (mat);
}
