/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:53:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 16:53:28 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
		if (ft_isdigit(*str++) == FALSE)
			return (FALSE);
	if (*str == '.')
		return (ft_is_numeric(++str));
	return (TRUE);
}

int	ft_is_triplet(char **tab)
{
	if (!tab)
		return (FALSE);
	if (ft_tabsize(tab) != 3)
		return (FALSE);
	while (*tab)
		if (!ft_is_float(*tab++))
			return (FALSE);
	return (TRUE);
}

int	ft_is_normalized(t_vector vector)
{
	return (ft_eq(ft_v_norm(vector), 1));
}
