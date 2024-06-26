/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/01 17:20:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_is_color(char **tab)
{
	size_t	i;
	size_t	j;

	if (ft_tabsize(tab) != 3)
		return (FALSE);
	j = 0;
	while (tab[j])
	{
		i = 0;
		if (!ft_is_numeric(tab[j]))
			return (FALSE);
		if (ft_strlen(tab[j]) > 3
			|| ft_atoi(tab[j]) > 255)
			return (FALSE);
		j++;
	}
	return (TRUE);
}

int	ft_set_color(t_color *color, char *arg)
{
	char	**rgb;

	rgb = ft_split(arg, ',');
	if (!rgb)
		return (ft_error("ft_split", TRUE));
	if (ft_is_color(rgb) == FALSE)
	{
		ft_free_tab((void **) rgb);
		return (ft_error("wrong color format", FALSE));
	}
	*color = ft_color(
			(double) ft_atoi(rgb[0]) / 255.0,
			(double) ft_atoi(rgb[1]) / 255.0,
			(double) ft_atoi(rgb[2]) / 255.0);
	ft_free_tab((void **)rgb);
	return (EXIT_SUCCESS);
}
