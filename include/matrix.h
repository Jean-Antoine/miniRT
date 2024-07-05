/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/05 16:48:14 by lpaquatt         ###   ########.fr       */
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
t_tuple	ft_tup_prod_mat(t_mat A, t_tuple tuple);
t_mat	ft_translate(t_mat matrix, t_tuple translation);
t_mat	ft_scale(t_mat matrix, double x, double y, double z);
t_mat	ft_rotate_x(t_mat matrix, double r);
t_mat	ft_rotate_y(t_mat matrix, double r);
t_mat	ft_rotate_z(t_mat matrix, double r);
t_mat	ft_rotation_x(double r);
t_mat	ft_rotation_y(double r);
t_mat	ft_rotation_z(double r);
t_mat	ft_mat_id(int size);

#endif