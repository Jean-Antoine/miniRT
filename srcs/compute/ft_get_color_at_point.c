/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_at_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/05 16:59:51 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_color	ft_lighting_ambient(t_inters hit, t_scene *scene)
{
	t_material	material;
	t_color		ambient;

	material = hit.object->material;
	ambient = ft_color_mix(
			hit.comp.color_at_pt,
			ft_color_brightness(scene->ambient_brightness,
				scene->ambient_color));
	return (ambient);
}

t_color	ft_get_color_at_point(t_inters hit, t_scene *scene)
{
	t_light			*light;
	t_light_comp	comp;
	t_color			out;

	hit.comp.ambient = ft_lighting_ambient(hit, scene);
	light = scene->lights;
	if (!light)
		return (hit.comp.ambient);
	out = ft_black();
	while (light)
	{
		comp.light_v = ft_v_normalize(
				ft_p_to_v(hit.comp.point, light->position));
		comp.reflect_v = ft_reflect(
				ft_v_scalar_prod(-1, comp.light_v), hit.comp.normal_v);
		comp.light_dot_normal = ft_v_dot_prod(comp.light_v, hit.comp.normal_v);
		comp.reflect_dot_eye = ft_v_dot_prod(comp.reflect_v, hit.comp.eye_v);
		out = ft_color_add(out, ft_lighting(comp, hit, light, scene));
		light = light->next;
	}
	return (out);
}
