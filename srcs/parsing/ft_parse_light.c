/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:44:35 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/05 16:55:17 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_set_brightness(double *brightness, char *arg)
{
	if (ft_is_float(arg) == FALSE)
		return (ft_error("wrong brightness format", FALSE));
	*brightness = ft_atof(arg);
	if (*brightness < 0 || *brightness > 1)
		return (ft_error("brightness must be between 0 and 1", FALSE));
	return (EXIT_SUCCESS);
}

static int	ft_parse_spot_light(char **args, t_light *light)
{
	if (ft_tabsize(args) != 4)
		return (ft_error("wrong number of parameters", FALSE));
	if (ft_set_point(&light->position, args[1]))
		return (EXIT_FAILURE);
	if (ft_set_brightness(&light->brightness_ratio, args[2]))
		return (EXIT_FAILURE);
	if (ft_set_color(&light->color, args[3]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_parse_ambiant_light(char **args, t_scene *scene)
{
	static int	i = 0;

	if (i++)
		return (ft_error("more than one ambiant light", FALSE));
	if (ft_tabsize(args) != 3)
		return (ft_error("wrong number of parameters", FALSE));
	if (ft_set_brightness(&scene->ambient_brightness, args[1]))
		return (EXIT_FAILURE);
	if (ft_set_color(&scene->ambient_color, args[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_light	*ft_new_light_addback(t_light **light_lst)
{
	t_light	*new_light;
	t_light	*last;

	new_light = ft_calloc(1, sizeof(t_light));
	if (!new_light)
		return (NULL);
	if (!*light_lst)
		*light_lst = new_light;
	else
	{
		last = *light_lst;
		while (last->next)
			last = last->next;
		last->next = new_light;
	}
	return (new_light);
}

int	ft_parse_light(char **args, t_scene *scene)
{
	t_light	*light;

	if (ft_strcmp(args[0], "L")
		&& ft_strcmp(args[0], "A"))
		return (2);
	if (!ft_strcmp(args[0], "A"))
		return (ft_parse_ambiant_light(args, scene));
	light = ft_new_light_addback(&scene->lights);
	if (!light)
		return (ft_error("ft_parse_light", TRUE));
	return (ft_parse_spot_light(args, light));
}
