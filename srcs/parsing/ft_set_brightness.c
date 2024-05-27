/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_brightness.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 17:18:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_set_brightness(double *brightness, char *arg)
{
	if (ft_is_float(arg) == FALSE)
		return (ft_error("Invalid data\n", FALSE));
	*brightness = ft_atof(arg);
	if (*brightness < 0 || *brightness > 1)
		return (ft_error("Invalid data\n", FALSE));
	return (EXIT_SUCCESS);
}
