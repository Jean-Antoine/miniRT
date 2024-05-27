/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_spot_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:15 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 17:20:29 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_create_spot_light(char **args, t_scene *scene)
{
	t_light	*light;

	if (ft_tabsize(args) != 4)
		return (ft_error("Invalid data in file\n", FALSE));
	light = ft_new_light_addback(&scene->lights);
	if (!light)
		return (EXIT_FAILURE);
	if (ft_get_point(&light->position, args[1]))
		return (EXIT_FAILURE);
	if (ft_set_brightness(&light->brightness_ratio, args[2]))
		return (EXIT_FAILURE);
	if (ft_set_color_from_arg(&light->color, args[3]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
