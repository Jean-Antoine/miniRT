/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_light_brightness.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 16:15:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_set_light_brightness(double *brightness, char *arg)
{
	if (!ft_is_float(arg))
		return (ft_error("Invalid data\n", FALSE));
	*brightness = ft_atof(arg);
	if (*brightness < 0 || *brightness > 1)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
