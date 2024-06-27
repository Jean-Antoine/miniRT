/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_at_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/27 19:10:33 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_color	ft_diffuse(double light_dot_normal,	double mat_diffuse,
	t_color eff_color)
{
	if (light_dot_normal < 0)
		return (ft_black());
	return (ft_color_brightness(light_dot_normal * mat_diffuse, eff_color));
}

t_color	ft_specular(t_light_comp l, double shininess, double specular,
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

t_bool	ft_is_shadowed(t_point pt, t_light light, t_scene scene)
{
	t_vector	pt_to_light;
	double		distance;
	t_ray		ray;
	t_inters	*hit;

	pt_to_light = ft_p_to_v(pt, light.position);
	distance = ft_v_norm(pt_to_light);
	ray = ft_ray(pt, ft_v_normalize(pt_to_light));
	ft_inters(scene, &ray); //faut pas qu'il intersecte avec lui même
	hit = ft_hit(&ray.inters_lst);
	if (hit && hit->t < distance)
	{
		ft_free_inters_lst(ray.inters_lst);
		return (TRUE);
	}
	ft_free_inters_lst(ray.inters_lst);
	return (FALSE);
}

t_color	ft_lighting(t_light_comp l, t_inters hit, t_light *light,
	t_scene *scene)
{
	t_material	material;
	t_color		ambient;
	t_color		eff_color;
	t_color		diffuse;
	t_color		specular;

	material = hit.object->material;
	eff_color = ft_color_mix(
			ft_color_brightness(light->brightness_ratio, light->color),
			material.color);
	ambient = ft_color_mix(
			eff_color,
			ft_color_brightness(scene->ambient_brightness,
				scene->ambient_color));
	if (ft_is_shadowed(hit.comp.point, *light, *scene) == TRUE)
		return (ambient);
	diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
	specular = ft_specular(l, material.shininess, material.specular,
			ft_color_brightness(light->brightness_ratio, light->color));
	return (ft_color_add(ambient, ft_color_add(diffuse, specular)));
}

t_color	ft_get_color_at_point(t_inters hit, t_scene *scene)
{
	t_light			*light;
	t_light_comp	comp;
	t_color			out;

	light = scene->lights;
	if (!light)
		return (ft_color_mix(
				hit.object->material.color,
				ft_color_brightness(
					scene->ambient_brightness,
					scene->ambient_color)));
	out = ft_black();
	while (light)
	{
		comp.light_v = ft_v_normalize(ft_p_to_v(hit.comp.point, light->position));
		//comp.normal_v = ft_normal_at(hit.object, hit.comp.point);
		comp.reflect_v = ft_reflect(ft_v_scalar_prod(-1, comp.light_v), hit.comp.normal_v);
		comp.light_dot_normal = ft_v_dot_prod(comp.light_v, hit.comp.normal_v);
		comp.reflect_dot_eye = ft_v_dot_prod(comp.reflect_v, hit.comp.eye_v);
		out = ft_color_add(out, ft_lighting(comp, hit, light, scene));
		light = light->next;
	}
	return (out);
}
