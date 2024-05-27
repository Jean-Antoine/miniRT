/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/27 15:38:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_is_numeric(char *str)
{
	if (!str)
		return (FALSE);
	if (*str == '-')
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	return (TRUE);
}

int	ft_is_float(char *str)
{
	if (!str)
		return (FALSE);
	if (*str == '-')
		str++;
	if (*str == '.')
		return (FALSE);
	while (*str && *str != '.')
		if (ft_isdigit(*str++))
			return (FALSE);
	if (*str == '.')
		return (ft_is_numeric(++str));
	return (TRUE);
}
