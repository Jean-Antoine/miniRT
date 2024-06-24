/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:46:48 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/24 17:54:07 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_mat	ft_submatrix(t_mat A, int i, int j)
{
	t_mat	result;
	int		x;
	int		y;

	result.col = A.col - 1;
	result.row = A.row - 1;
	x = -1;
	while (++x < A.row)
	{
		y = -1;
		while (++y < A.col)
			result.mat[x][y] = A.mat[x + 1 * (x >= i)][y + 1 * (y >= j)];
	}
	return (result);
}

static double	ft_cofactor(t_mat A, int i, int j);

static double	ft_mat_discr(t_mat A)
{
	int		i;
	double	d;

	if (A.col == 2)
		return (A.mat[0][0] * A.mat[1][1]
			- A.mat[0][1] * A.mat[1][0]);
	i = -1;
	d = 0;
	while (++i < A.col)
		d += ft_cofactor(A, 0, i) * A.mat[0][i];
	return (d);
}

static double	ft_cofactor(t_mat A, int i, int j)
{
	if ((i + j) % 2)
		return (-ft_mat_discr(ft_submatrix(A, i, j)));
	return (ft_mat_discr(ft_submatrix(A, i, j)));
}

int	ft_is_inv(t_mat A)
{
	return (ft_mat_discr(A) != 0);
}

t_mat	ft_mat_inv(t_mat A)
{
	t_mat	inv;
	int		i;
	int		j;
	double	d;

	inv.col = A.col;
	inv.row = A.row;
	i = -1;
	d = ft_mat_discr(A);
	while (++i < A.col)
	{
		j = -1;
		while (++j < A.col)
			inv.mat[j][i] = ft_cofactor(A, i, j) / d;
	}
	return (inv);
}

// int	main(void)
// {
// 	t_mat	A;

// 	A = ft_matrix(4, 4);
// 	A.mat[0][0] = 9; A.mat[0][1] = 25; A.mat[0][2] = 2; A.mat[0][3] = 1;
// 	A.mat[1][0] = 3; A.mat[1][1] = 1; A.mat[1][2] = 5; A.mat[1][3] = 7;
// 	A.mat[2][0] = 1; A.mat[2][1] = 5; A.mat[2][2] = 5; A.mat[2][3] = 3;
// 	A.mat[3][0] = 1; A.mat[3][1] = 2; A.mat[3][2] = 3; A.mat[3][3] = 4;
// 	ft_mat_print(ft_mat_inv(A));
// }