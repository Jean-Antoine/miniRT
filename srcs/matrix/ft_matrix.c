/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:03:33 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/11 14:07:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_matrix(int row, int col)
{
	t_mat	mat;

	ft_bzero(&mat, sizeof(t_mat));
	mat.row = row;
	mat.col = col;
	return (mat);
}
