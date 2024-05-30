/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:47:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/30 14:35:12 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "stdio.h"

void	ft_mat_print(t_mat A)
{
	int	i;
	int	j;

	i = -1;
	while (++i < A.row)
	{
		j = -1;
		while (++j < A.col)
			printf("% 3f  ", A.mat[i][j]);
		printf("\n");
	}
}