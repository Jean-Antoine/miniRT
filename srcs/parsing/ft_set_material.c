/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:35:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/01 17:15:16 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
	material.diffuse between 0 and 1
	material.specular between 0 and 1
	material.shininess between 10 and 200
	material.pattern is a boolean
*/

static int	ft_is_material(char **tab)
{
	if (ft_tabsize(tab) != 4)
		return (FALSE);
	if (!ft_is_float(tab[0]) || !ft_is_float(tab[1]) || !ft_is_float(tab[2])
		|| !ft_is_numeric(tab[3]))
		return (FALSE);
	if (ft_atof(tab[0]) < 0 || ft_atof(tab[0]) > 1)
		return (FALSE);
	if (ft_atof(tab[1]) < 0 || ft_atof(tab[1]) > 1)
		return (FALSE);
	if (ft_atof(tab[2]) < 10 || ft_atof(tab[2]) > 200)
		return (FALSE);
	if (ft_atoi(tab[3]) != 0 && ft_atoi(tab[3]) != 1)
		return (FALSE);
	return (TRUE);
}

int	ft_set_material(t_material *material, char *arg)
{
	char	**args;

	args = ft_split(arg, ',');
	if (!args)
		return (ft_error("ft_split", TRUE));
	if (ft_is_material(args) == FALSE)
	{
		ft_free_tab((void **)args);
		return (ft_error("wrong material format", FALSE));
	}
	material->diffuse = ft_atof(args[0]);
	material->specular = ft_atof(args[1]);
	material->shininess = ft_atof(args[2]);
	material->pattern = ft_atoi(args[3]);
	ft_free_tab((void **)args);
	return (EXIT_SUCCESS);
}
