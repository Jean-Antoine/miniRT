/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:47:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/18 17:23:07 by jeada-si         ###   ########.fr       */
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
			printf("% 6f  ", A.mat[i][j]);
		printf("\n");
	}
	printf("\n");
}
