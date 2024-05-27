/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 17:22:53 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_is_color(char **tab)
{
	size_t	i;
	size_t	j;

	if (ft_tabsize(tab) != 3)
		return (KO);
	j = 0;
	while (tab[j])
	{
		i = 0;
		if (!ft_is_numeric(tab[j]))
			return (KO);
		if (ft_strlen(tab[j]) > 3
			|| ft_atoi(tab[j]) > 255)
			return (KO);
		j++;
	}
	return (OK);
}

int	ft_set_color(t_color *color, char *arg)
{
	char	**rgb;

	rgb = ft_split(arg, ',');
	if (!rgb)
	{
		perror("ft_split");
		return (EXIT_FAILURE);
	}
	if (ft_is_color(rgb) == KO)
	{
		ft_free_tab((void **) rgb);
		ft_putstr_fd("Error: invalid data in file\n", 2);
		return (EXIT_FAILURE);
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	ft_free_tab((void **)rgb);
	return (EXIT_SUCCESS);
}
