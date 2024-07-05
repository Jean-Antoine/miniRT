/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:23:04 by jeada-si          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/07/04 17:31:07 by lpaquatt         ###   ########.fr       */
=======
/*   Updated: 2024/07/03 11:28:03 by jeada-si         ###   ########.fr       */
>>>>>>> 46b5a25 (cone cyl)
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
t_mat	ft_translate(t_mat matrix, t_tuple translation);
t_mat	ft_scale(t_mat matrix, double x, double y, double z);
t_mat	ft_rotate_x(t_mat matrix, double r);
t_mat	ft_rotate_y(t_mat matrix, double r);
t_mat	ft_rotate_z(t_mat matrix, double r);
t_mat	ft_mat_id(int size);

#endif