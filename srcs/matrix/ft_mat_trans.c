/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:41:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/29 16:46:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_mat_trans(t_mat A)
{
	t_mat	result;
	int		i;
	int		j;

	i = -1;
	result.col = A.row;
	result.row = A.col;
	while (++i < A.col)
	{
		j = -1;
		while (++j < A.row)
			result.mat[i][j] = A.mat[j][i];
	}
	return (result);
}
