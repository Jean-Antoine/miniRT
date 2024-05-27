/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_color_from_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:21 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 15:46:17 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_check_arg_color(char **tab)
{
	size_t	i;
	size_t	j;

	if (ft_tabsize(tab) != 3)
		return (KO);
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (!(tab[j][i] >= '0' && tab[j][i] <= '9'))
				return (KO);
			i++;
		}
		if (ft_strlen(tab[j]) > 3
			|| ft_atoi(tab[j]) > 255)
			return (KO);
		j++;
	}
	return (OK);
}

int	ft_set_color_from_arg(t_color *color, char *arg)
{
	char	**rgb;

	rgb = ft_split(arg, ',');
	if (!rgb)
	{
		perror("ft_split");
		return (EXIT_FAILURE);
	}
	if (ft_check_arg_color(rgb) == KO)
	{
		ft_free_tab((void **)rgb);
		ft_putstr_fd("Error : invalid data in file\n", 2);
		return (EXIT_FAILURE);
	}
	*color = ft_set_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_tab((void **)rgb);
	return (EXIT_SUCCESS);
}
