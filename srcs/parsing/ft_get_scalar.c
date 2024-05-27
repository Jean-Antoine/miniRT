/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_scalar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:08:09 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/27 17:09:19 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_get_scalar(int *dest, char *str)
{
	if (!str)
		return (EXIT_FAILURE);
	if (!ft_is_float(str))
		return (EXIT_FAILURE);
	*dest = ft_atof(str);
	return (EXIT_SUCCESS);
}
