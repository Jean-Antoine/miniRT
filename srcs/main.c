/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:26:01 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 17:52:53 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	ft_free_lights(t_light *light)
{
	t_light	*next;

	while (light)
	{
		next = light->next;
		free(light);
		light = next;
	}
}

void	ft_free_objects(t_object *object)
{
	t_object	*next;

	while (object)
	{
		next = object->next;
		free(object);
		object = next;
	}
}

void	ft_free_scene(t_scene scene)
{
	if (scene.ambiant_light)
		ft_free_lights(scene.ambiant_light);
	if (scene.lights)
		ft_free_lights(scene.lights);
	if (scene.objects)
		ft_free_objects(scene.objects);
}

int	ft_exit(int exit_code, t_scene scene)
{
	ft_free_scene(scene);
	return (exit_code);
}

int	main(int ac, char **av)
{
	t_scene	scene;

	if (ft_parse_scene(&scene, ac, av) == EXIT_FAILURE)
		return (ft_exit(EXIT_FAILURE, scene));
	return (ft_exit(EXIT_SUCCESS, scene));
}
