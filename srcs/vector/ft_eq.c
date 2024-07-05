/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eq.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:43:43 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/04 17:44:17 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static double	ft_abs_(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_eq(double a, double b)
{
	return (ft_abs_(a - b) < TOLERANCE);
}
