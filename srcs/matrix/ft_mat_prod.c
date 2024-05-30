/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_prod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:28:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/30 12:01:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat	ft_mat_prod(t_mat A, t_mat B)
{
	t_mat	result;
	int		i;
	int		j;
	int		k;

	ft_bzero(&result, sizeof(result));
	if (A.col != B.row)
	{
		ft_putstr_fd("Matrix not compatible\n", STDERR_FILENO);
		return (result);
	}		
	result.row = A.row;
	result.col = B.col;
	i = -1;
	while (++i < result.row)
	{
		j = -1;
		while (++j < result.col)
		{
			k = -1;
			while (++k < A.col)
				result.mat[i][j] += A.mat[i][k] * B.mat[k][j];
		}
	}
	return (result);
}
