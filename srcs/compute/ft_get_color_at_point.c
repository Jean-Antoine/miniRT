/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_at_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/21 13:32:37 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

double	ft_color_brightness(t_color color)
{
	return (0.2126 * color.x / 255 + 0.7152 * color.y / 255 + 0.0722 * color.y / 255);
}

t_color	ft_apply_brightness(t_color color, double brightness)
{
	return (ft_v_scalar_prod(brightness, color));
}

t_color	ft_get_color_at_point(t_object obj, t_point pt, t_light light, t_vector camera_dir)
{
	t_color		eff_color;
	t_color		ambiant;
	t_color		diffuse;
	t_color		specular;
	t_vector	light_v;
	t_vector	normal_v;
	t_vector	reflect_v;
	double		light_dot_normal;
	double		reflect_dot_eye;

	eff_color = ft_apply_brightness(obj.material.color, light.brightness_ratio);
	light_v = ft_v_normalize(ft_p_to_v(pt, light.position));
	ambiant = ft_apply_brightness(eff_color, obj.material.ambiant);
	normal_v = ft_normal_at(obj, pt);
	light_dot_normal = ft_v_dot_prod(light_v, normal_v); //sp only
	diffuse = ft_color(0, 0, 0);
	specular = ft_color(0, 0, 0);
	if (light_dot_normal > 0)
	{
		diffuse = ft_apply_brightness(eff_color, obj.material.diffuse * light_dot_normal);
		reflect_v = ft_reflect(ft_v_scalar_prod(-1, light_v), normal_v);
		reflect_dot_eye = ft_v_dot_prod(reflect_v, camera_dir);
		if (reflect_dot_eye <= 0)
			specular = ft_color(0, 0, 0);
		else
			specular = ft_apply_brightness(
				ft_color(255, 255, 255), 
				light.brightness_ratio * obj.material.specular * pow(reflect_dot_eye, obj.material.shininess));
	}
	return (ft_v_add(ambiant, ft_v_add(diffuse, specular)));
}
