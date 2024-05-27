/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_light_brightness.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 15:49:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_set_light_brightness(double *brightness, char *arg)
{
	if (!ft_isfloat(arg))
	{
		ft_putstr_fd("Error : invalid data in file\n", 2);
		return (EXIT_FAILURE);
	}
	*brightness = ft_atof(arg);
	if (*brightness < 0 || *brightness > 1)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
