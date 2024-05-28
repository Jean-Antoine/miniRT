/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:44:35 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/27 18:05:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_parse_spot_light(char **args, t_light *light)
{
	if (ft_tabsize(args) != 4)
		return (ft_error("Invalid data in file\n", FALSE));
	if (ft_set_point(&light->position, args[1]))
		return (EXIT_FAILURE);
	if (ft_set_brightness(&light->brightness_ratio, args[2]))
		return (EXIT_FAILURE);
	if (ft_set_color(&light->color, args[3]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


static int	ft_parse_ambiant_light(char **args, t_light *light)
{
	if (ft_tabsize(args) != 3)
		return (ft_error("Invalid data.\n", FALSE));
	light->ambient_light = TRUE;
	if (ft_set_brightness(&light->brightness_ratio, args[1]))
		return (EXIT_FAILURE);
	if (ft_set_color(&light->color, args[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_light	*ft_new_light_addback(t_light **light_lst)
{
	t_light	*new_light;
	t_light	*last;

	new_light = ft_calloc(1, sizeof(t_light));
	if (!new_light)
	{
		ft_error("ft_parse_light", TRUE);
		return (NULL);
	}
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

int	ft_parse_light(char **args, t_light **dest)
{
	t_light*	light;
	
	if (ft_strcmp(args[0], "L")
		&& ft_strcmp(args[0], "A"))
		return (2);
	light = ft_new_light_addback(dest);
	if (!light)
		return (EXIT_FAILURE);
	if (!ft_strcmp(args[0], "A"))
		return (ft_parse_ambiant_light(args, light));
	if (!ft_strcmp(args[0], "L"))
		return (ft_parse_spot_light(args, light));
	return (EXIT_FAILURE);
}
