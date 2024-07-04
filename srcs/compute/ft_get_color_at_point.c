/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_at_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/07/04 16:22:57 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_color	ft_diffuse(double light_dot_normal,	double mat_diffuse,
	t_color eff_color)
{
	if (light_dot_normal < TOLERANCE)
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
	t_bool		out;

	pt_to_light = ft_p_to_v(pt, light.position);
	distance = ft_v_norm(pt_to_light);
	ray = ft_ray(pt, ft_v_normalize(pt_to_light));
	ft_inters(scene, &ray);
	hit = ft_hit(&ray.inters_lst);
	out = hit && hit->t < distance + TOLERANCE;
	ft_free_inters_lst(ray.inters_lst);
	return (out);
}

static t_color	ft_checker_at_point_sp(t_object *sphere, t_point point) // avec ft_color_at_point
{
	t_point	uv;

	uv = ft_get_uv_sp(point);
	if ((int)(floor(uv.x * CHECKERS_BY_UNIT * 5)
		+ floor(uv.y * CHECKERS_BY_UNIT * 5)) % 2 == 0)
		return (ft_color_mix(sphere->material.color, ft_grey()));
	return (sphere->material.color);
}

t_color	ft_color_at_point(t_object *object, t_point point) //a mettre ailleurs
{
	if (object->material.pattern == TRUE)
	{
		point = ft_mat_prod_tup(object->transform, point);
		if (object->type == sphere)
			return (ft_checker_at_point_sp(object, point));
		point = ft_v_scalar_prod(CHECKERS_BY_UNIT, point);
		if ((int)(floor(point.x + TOLERANCE) + floor(point.y + TOLERANCE)
			+ floor(point.z + TOLERANCE)) % 2 == 0)
			return (ft_color_mix(object->material.color, ft_grey()));
		return (object->material.color);
	}
	return (object->material.color);
}


/*good ?*/

t_color	ft_lighting_ambient(t_inters hit, t_scene *scene)
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

t_color	ft_lighting(t_light_comp l, t_inters hit, t_light *light,
	t_scene *scene, t_color ambient)
{
	t_material	material;
	t_color		eff_color;
	t_color		diffuse;
	t_color		specular;

	material = hit.object->material;
	eff_color = ft_color_mix(
			ft_color_brightness(light->brightness_ratio, light->color),
			hit.comp.color_at_pt);
	if (ft_is_shadowed(hit.comp.point, *light, *scene) == TRUE)
	{
		if (!material.texture.path)
			return (ambient);
		diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
		diffuse = ft_color_brightness(0.5, diffuse);
		// return(ambient);
		return (ft_color_add(ambient, diffuse));
	}
	diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
	specular = ft_specular(l, material.shininess, material.specular,
			ft_color_brightness(light->brightness_ratio, light->color));
	return (ft_color_add(ambient, ft_color_add(diffuse, specular)));
}

/*old*/

// t_color	ft_lighting(t_light_comp l, t_inters hit, t_light *light,
// 	t_scene *scene)
// {
// 	t_material	material;
// 	t_color		ambient;
// 	t_color		eff_color;
// 	t_color		diffuse;
// 	t_color		specular;

// 	material = hit.object->material;
// 	eff_color = ft_color_mix(
// 			ft_color_brightness(light->brightness_ratio, light->color),
// 			ft_color_at_point(hit.object,hit.comp.point)); // la lumiere affecte la couleur de l'objet meme quand il y a un objet entre les deux .. normal ?
// 	ambient = ft_color_mix(
// 			eff_color,
// 			ft_color_brightness(scene->ambient_brightness,
// 				scene->ambient_color));
// 	if (ft_is_shadowed(hit.comp.point, *light, *scene) == TRUE)
// 		return (ambient);
// 	diffuse = ft_diffuse(l.light_dot_normal, material.diffuse, eff_color);
// 	specular = ft_specular(l, material.shininess, material.specular,
// 			ft_color_brightness(light->brightness_ratio, light->color));
// 	return (ft_color_add(ambient, ft_color_add(diffuse, specular)));
// }


t_color	ft_get_color_at_point(t_inters hit, t_scene *scene)
{
	t_light			*light;
	t_light_comp	comp;
	t_color			out;
	t_color			ambient;

	ambient = ft_lighting_ambient(hit, scene);
	light = scene->lights;
	if (!light)
		return (ambient);
	out = ft_black();
	while (light)
	{
		comp.light_v = ft_v_normalize(ft_p_to_v(hit.comp.point, light->position));
		comp.reflect_v = ft_reflect(ft_v_scalar_prod(-1, comp.light_v), hit.comp.normal_v);
		comp.light_dot_normal = ft_v_dot_prod(comp.light_v, hit.comp.normal_v);
		comp.reflect_dot_eye = ft_v_dot_prod(comp.reflect_v, hit.comp.eye_v);
		// out = ft_color_add(out, ft_lighting(comp, hit, light, scene));
		out = ft_color_add(out, ft_lighting(comp, hit, light, scene, ambient));
		light = light->next;
	}
	return (out);
}
