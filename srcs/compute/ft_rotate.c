/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:31:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 14:32:46 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_mat	ft_rotate(t_mat mat, t_vector vector)
{
	double	theta_x;
	double	theta_z;

	theta_x = atan2(vector.z, sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
	theta_z = atan2(vector.x, vector.y);
	mat = ft_rotate_z(mat, theta_z);
	mat = ft_rotate_x(mat, theta_x);
	return (mat);
}
