/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_color_from_arg.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 15:34:37 by jeada-si         ###   ########.fr       */
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

int	ft_create_color_from_arg(t_color *color, char *str)
{
	char	**rgb;

	rgb = ft_split(str, ',');
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
	*color = ft_create_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_tab((void **)rgb);
	return (EXIT_SUCCESS);
}
