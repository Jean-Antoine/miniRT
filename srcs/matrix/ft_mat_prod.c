/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_prod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:28:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/01 17:21:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "vector.h"

t_mat	ft_mat_prod(t_mat A, t_mat B)
{
	t_mat	result;
	int		i;
	int		j;
	int		k;

	result = ft_matrix(A.row, B.col);
	if (A.col != B.row)
	{
		ft_putstr_fd("Matrix not compatible\n", STDERR_FILENO);
		return (result);
	}	
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
