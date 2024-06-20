/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_prod_tup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:58:10 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/18 17:24:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double	ft_somprod(double *A, t_tuple tuple)
{
	return (A[0] * tuple.x + A[1] * tuple.y + A[2] * tuple.z + A[3] * tuple.w);
}

t_tuple	ft_mat_prod_tup(t_mat A, t_tuple tuple)
{
	t_tuple	res;

	res.x = ft_somprod(A.mat[0], tuple);
	res.y = ft_somprod(A.mat[1], tuple);
	res.z = ft_somprod(A.mat[2], tuple);
	res.w = ft_somprod(A.mat[3], tuple);
	return (res);
}

// int	main(void)
// {
// 	t_mat	A;
// 	t_tuple	tuple;

// 	A.mat[0][0] = 1; A.mat[0][1] = 1; A.mat[0][2] = 1; A.mat[0][3] = 1;
// 	A.mat[1][0] = 2; A.mat[1][1] = 2; A.mat[1][2] = 2; A.mat[1][3] = 2;
// 	A.mat[2][0] = 3; A.mat[2][1] = 3; A.mat[2][2] = 3; A.mat[2][3] = 3;
// 	A.mat[3][0] = 4; A.mat[3][1] = 4; A.mat[3][2] = 4; A.mat[3][3] = 4;

// 	ft_mat_print(A);
	
// 	tuple.x = 1;
// 	tuple.y = 1;
// 	tuple.z = 1;
// 	tuple.w = 1;
// 	tuple = ft_mat_prod_tup(A, tuple);
// 	printf("%f, %f, %f, %f\n", tuple.x, tuple.y, tuple.z, tuple.w);
// }