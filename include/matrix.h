/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/30 12:45:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# define MAT_MAX_SIZE 4
# include "libft.h"

typedef struct s_matrix
{
	int		row;
	int		col;
	double	mat[MAT_MAX_SIZE][MAT_MAX_SIZE];
}	t_mat;

void	ft_mat_print(t_mat A);
t_mat	ft_mat_prod(t_mat A, t_mat B);
t_mat	ft_mat_trans(t_mat A);
t_mat	ft_mat_inv(t_mat A);
int		ft_is_inv(t_mat A);
#endif