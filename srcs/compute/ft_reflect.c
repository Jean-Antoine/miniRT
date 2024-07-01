/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:52:46 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/01 17:26:54 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_vector	ft_reflect(t_vector light, t_vector normal)
{
	t_vector	reflection;

	reflection = ft_v_scalar_prod(-2 * ft_v_dot_prod(light, normal), normal);
	reflection = ft_v_add(light, reflection);
	return (reflection);
}
