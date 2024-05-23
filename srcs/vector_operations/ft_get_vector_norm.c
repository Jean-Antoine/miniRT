/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vector_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:55:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:00:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	ft_get_vector_norm(t_vector vect)
{
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}
