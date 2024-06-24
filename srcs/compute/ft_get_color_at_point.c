/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_at_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/24 18:04:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_color	ft_black(void)
{
	return (ft_color(0, 0, 0));
}

t_color	ft_white(void)
{
	return (ft_color(255, 255, 255));
}

t_color	ft_diffuse(double light_dot_normal,	double mat_diffuse, t_color eff_color)
{
	if (light_dot_normal < 0)
		return (ft_black());
	return (ft_color_brightness(light_dot_normal * mat_diffuse, eff_color));
}

t_color	ft_specular(t_light_comp l, double shininess, double specular, t_color light)
{
	double	factor;
	t_color	specular_; 
	
	if (l.light_dot_normal < TOLERANCE || l.reflect_dot_eye <= TOLERANCE)
		return (ft_black());
	factor = pow(l.reflect_dot_eye, shininess);
	specular_ = ft_color_brightness(
		factor * specular,
		light
	);
	return (specular_);
}

t_color	ft_lightning(t_light_comp l, t_material material, t_light *light, t_scene *scene)
{
	t_color		ambient;
	t_color		eff_color;
	t_color		diffuse;
	t_color		specular;

	eff_color = ft_color_mix(
		ft_color_brightness(light->brightness_ratio, light->color),
		material.color);
	ambient = ft_color_mix(
		eff_color, 
		ft_color_brightness(scene->ambient_brightness, scene->ambient_color));
	diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
	specular = ft_specular(l , material.shininess, material.specular,
		ft_color_brightness(light->brightness_ratio, light->color));
	return (ft_color_add(ambient, ft_color_add(diffuse, specular)));
}

t_color	ft_get_color_at_point(t_object *object, t_point pt, t_vector eye_v, t_scene *scene)
{
	t_light			*light;
	t_light_comp	comp;
	t_color			out;

	light = scene->lights;
	if (!light)
		return (ft_color_mix(
			object->material.color, 
			ft_color_brightness(
				scene->ambient_brightness, 
				scene->ambient_color)));
	out = ft_black();
	while (light)
	{
		comp.light_v = ft_v_normalize(ft_p_to_v(pt, light->position));
		comp.normal_v = ft_normal_at(object, pt);
		comp.reflect_v = ft_reflect(ft_v_scalar_prod(-1, comp.light_v), comp.normal_v);
		comp.light_dot_normal = ft_v_dot_prod(comp.light_v, comp.normal_v);
		comp.reflect_dot_eye = ft_v_dot_prod(comp.reflect_v, eye_v);		
		out = ft_color_add(out, ft_lightning(comp, object->material, light, scene));
		light = light->next;
	}
	return (out);
}