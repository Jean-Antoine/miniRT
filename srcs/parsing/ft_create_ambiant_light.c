/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ambiant_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:15 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 18:25:47 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_create_ambiant_light(char **args, t_scene *scene)
{
	t_light	*light;

	if (ft_tabsize(args) != 3)
	{
		ft_putstr_fd("Error : invalid data in file\n", 2);
		return (EXIT_FAILURE);
	}
	light = ft_new_light_addback(&scene->ambiant_light);
	if (!light)
		return (EXIT_FAILURE);
	light->ambient_light = TRUE;
	light->brightness_ratio = ft_atof(args[1]); //verifier que je n'ai pas de characteres interdits (derriere le atof)
	if (ft_create_color_from_arg(&light->color, args[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
