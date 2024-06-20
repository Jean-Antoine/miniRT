/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:57:04 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 11:06:35 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdio.h>
# define TOLERANCE 0.01

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef t_tuple	t_vector;
typedef t_tuple	t_point;

int			ft_eq(double a, double b);
t_point		ft_point(double x, double y, double z);
t_point		ft_p_translate(t_point starting_point, t_vector vector);
t_vector	ft_p_to_v(t_point starting_point, t_point end_point);
t_vector	ft_vector(double x, double y, double z);
t_vector	ft_v_add(t_vector v1, t_vector v2);
t_vector	ft_v_scalar_prod(double scalar, t_vector vector);
t_vector	ft_v_normalize(t_vector vector);
t_vector	ft_v_cross_prod(t_vector v1, t_vector v2);
double		ft_v_norm(t_vector vect);
double		ft_v_dot_prod(t_vector v1, t_vector v2);
void		ft_tuple_print(t_tuple tup);

#endif