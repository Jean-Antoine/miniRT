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

#ifndef operations_H
# define operations_H
# include "struct.h"

t_point		ft_p_set(double x, double y, double z);
t_point		ft_p_translate(t_point starting_point, t_vector vector);
t_vector	ft_p_to_v(t_point starting_point, t_point end_point);
t_vector	ft_v_set(double x, double y, double z);
t_vector	ft_v_add(t_vector v1, t_vector v2);
t_vector	ft_v_scalar_prod(double scalar, t_vector vector);
t_vector	ft_v_normalize(t_vector vector);
t_vector	ft_v_cross_prod(t_vector v1, t_vector v2);
double		ft_v_norm(t_vector vect);
double		ft_v_dot_prod(t_vector v1, t_vector v2);

#endif