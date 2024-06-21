/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/20 15:06:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# define MAT_MAX_SIZE 4
# include "libft.h"
# include "vector.h"

typedef struct s_matrix
{
	int		row;
	int		col;
	double	mat[MAT_MAX_SIZE][MAT_MAX_SIZE];
}	t_mat;

t_mat	ft_matrix(int row, int col);
void	ft_mat_print(t_mat A);
t_mat	ft_mat_prod(t_mat A, t_mat B);
t_mat	ft_mat_trans(t_mat A);
t_mat	ft_mat_inv(t_mat A);
int		ft_is_inv(t_mat A);
t_tuple	ft_mat_prod_tup(t_mat A, t_tuple tuple);
t_mat	ft_translation(double x, double y, double z);
t_mat	ft_scaling(double x, double y, double z);
t_mat	ft_rotation_x(double r);
t_mat	ft_rotation_y(double r);
t_mat	ft_rotation_z(double r);
t_mat	ft_mat_id(int size);

#endif