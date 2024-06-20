/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_at_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:46:10 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/18 16:34:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_color	ft_apply_light_to_color(t_color color, double brightness)
{
	return ((t_color)
		{color.r * brightness, color.g * brightness, color.b * brightness});
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_color ft_sum_colors(t_color col1, t_color col2)
{
	return ((t_color){ft_min(col1.r + col2.r, 255), ft_min(col1.g + col2.g, 255), ft_min(col1.b + col2.b, 255)});
	//return ((t_color){col1.r + col2.r, col1.g + col2.g, col1.b + col2.b});
}

t_color	ft_get_color_at_point(t_object obj, t_point pt, t_light light, t_scene scene)
{
	t_color	eff_color;
	t_color	ambiant;
	t_color diffuse;
	t_color	specular;
	t_vector	light_v;
	t_vector	normal_v;
	t_vector	reflect_v;
	double	light_dot_normal;
	double	reflect_dot_eye;

	eff_color = ft_apply_light_to_color(obj.material.color, light.brightness_ratio);
	light_v = ft_v_normalize(ft_p_to_v(pt, light.position));
	ambiant = ft_apply_light_to_color(eff_color, obj.material.ambiant);
	normal_v = ft_get_normal_at_sp(obj, pt);
	light_dot_normal = ft_v_dot_prod(light_v, normal_v); //sp only
	if (light_dot_normal < 0)
	{
		diffuse = (t_color){0,0,0};
		specular = (t_color){0,0,0};
	}
	else
	{
		diffuse = ft_apply_light_to_color(eff_color, obj.material.diffuse * light_dot_normal);
		reflect_v = ft_reflect(ft_v_scalar_prod(-1, light_v), normal_v);
		reflect_dot_eye = ft_v_dot_prod(reflect_v, scene.camera.direction);
		if (reflect_dot_eye <= 0)
			specular = (t_color){0,0,0};
		else
			specular = ft_apply_light_to_color(eff_color, light.brightness_ratio *
				obj.material.diffuse * pow(reflect_dot_eye, obj.material.shininess));
	}
	//return (ft_sum_colors(ambiant, diffuse));
	return (ft_sum_colors(ambiant, ft_sum_colors(diffuse, specular)));
}
