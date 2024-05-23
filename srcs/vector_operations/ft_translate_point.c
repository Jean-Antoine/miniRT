/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:54:52 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/23 17:01:57 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_point	ft_translate_point(t_point starting_point, t_vector vector)
{
	starting_point.x += vector.x;
	starting_point.y += vector.y;
	starting_point.z += vector.z;
	return (starting_point);
}
