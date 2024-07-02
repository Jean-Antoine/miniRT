/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:31:40 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/02 13:42:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_color	ft_black(void)
{
	return (ft_color(0, 0, 0));
}

t_color	ft_white(void)
{
	return (ft_color(1, 1, 1));
}

t_color	ft_grey(void)
{
	return (ft_color(0.5, 0.5, 0.5));
}
