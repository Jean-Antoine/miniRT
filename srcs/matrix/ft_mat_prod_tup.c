/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_prod_tup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:58:10 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/01 17:21:49 by lpaquatt         ###   ########.fr       */
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
