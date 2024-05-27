/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:04:28 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/27 17:30:23 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_get_point(t_point *dest, char *str)
{
	char	**tab;
	int		exit_code;
	
	if (!str)
		return (EXIT_FAILURE);
	tab = ft_split(str, ',');
	if (!tab)
		return (ft_error("ft_split", TRUE));
	exit_code = !ft_is_triplet(tab);
	if (exit_code)
		ft_error("Invalid data.\n", FALSE);
	else
		*dest = ft_p_set(ft_atof(tab[0]), ft_atof(tab[1]), ft_atof(tab[2]));
	ft_free_tab((void **) tab);
	return (exit_code);
}

int	ft_get_vector(t_vector *dest, char *str)
{
	if (ft_get_point((t_point *) dest, str))
		return (EXIT_FAILURE);
	return (!ft_is_normalized(*dest));
}
