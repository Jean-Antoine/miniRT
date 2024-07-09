/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lighting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:35:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/09 16:10:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_color	ft_diffuse(double light_dot_normal,	double mat_diffuse,
	t_color eff_color)
{
	if (light_dot_normal < TOLERANCE)
		return (ft_black());
	return (ft_color_brightness(light_dot_normal * mat_diffuse, eff_color));
}

static t_color	ft_specular(t_light_comp l, double shininess, double specular,
	t_color light)
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

static t_bool	ft_is_shadowed(t_point pt, t_light *light, t_scene *scene)
{
	t_vector	pt_to_light;
	double		distance;
	t_ray		ray;
	t_bool		out;

	pt_to_light = ft_p_to_v(pt, light->position);
	distance = ft_v_norm(pt_to_light);
	ray = ft_ray(pt, ft_v_normalize(pt_to_light));
	ft_inters(scene, &ray);
	out = (ray.inters_lst && ray.inters_lst->t < distance + TOLERANCE);
	ft_free_inters_lst(ray.inters_lst);
	return (out);
}

t_color	ft_lighting(t_light_comp l, t_inters hit, t_light *light,
	t_scene *scene)
{
	t_material	material;
	t_color		eff_color;
	t_color		diffuse;
	t_color		specular;

	material = hit.object->material;
	eff_color = ft_color_mix(
			ft_color_brightness(light->brightness_ratio, light->color),
			hit.comp.color_at_pt);
	if (ft_is_shadowed(hit.comp.point, light, scene) == TRUE)
	{
		if (!material.texture.path)
			return (hit.comp.ambient);
		diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
		diffuse = ft_color_brightness(0.5, diffuse);
		return (ft_color_add(hit.comp.ambient, diffuse));
	}
	diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
	specular = ft_specular(l, material.shininess, material.specular,
			ft_color_brightness(light->brightness_ratio, light->color));
	return (ft_color_add(hit.comp.ambient, ft_color_add(diffuse, specular)));
}
