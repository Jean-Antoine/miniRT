/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:57:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 11:41:59 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_OPERATIONS_H
# define VECTOR_OPERATIONS_H
# include "struct.h"



t_point		ft_create_point(double x, double y, double z);
t_vector	ft_create_vector(double x, double y, double z);
double		ft_get_vector_norm(t_vector vect);
t_vector	ft_create_vector_from_points(t_point starting_point,
				t_point end_point);
t_point		ft_translate_point(t_point starting_point, t_vector vector);
t_vector	ft_add_vectors(t_vector vector1, t_vector vector2);
t_vector	ft_multiply_vector_by_num(double factor, t_vector vector);
t_vector	ft_normalize_vector(t_vector vector);
double		ft_dot_product_vectors(t_vector vector1, t_vector vector2);
t_vector	ft_cross_product_vectors(t_vector vector1, t_vector vector2);



#endif