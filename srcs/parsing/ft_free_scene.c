/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:34:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/03 15:42:03 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_free_lights(t_light *light)
{
	t_light	*next;

	while (light)
	{
		next = light->next;
		free(light);
		light = next;
	}
}

static void	ft_free_objects(t_object *object)
{
	t_object	*next;

	while (object)
	{
		next = object->next;
		if (object->material.texture.img_buff)
			free(object->material.texture.img_buff);
		free(object);
		object = next;
	}
}

void	ft_free_scene(t_scene scene)
{
	if (scene.lights)
		ft_free_lights(scene.lights);
	if (scene.objects)
		ft_free_objects(scene.objects);
}
