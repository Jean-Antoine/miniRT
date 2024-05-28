/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:41:09 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/28 11:50:26 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef int					t_bool;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef enum e_object_type
{
	plan,
	sphere,
	cylinder
}	t_object_type;

typedef struct s_object
{
	t_object_type	type;
	t_point			position;
	double			diameter;
	double			height;
	t_vector		direction;
	t_color			color;
	struct s_object	*next;
}	t_object;

typedef struct s_light
{
	t_bool			ambient_light;
	t_point			position;
	double			brightness_ratio;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_camera
{
	t_point			position;
	t_vector		direction;
	double			fov;
}	t_camera;

typedef struct s_scene
{
	t_camera	camera;
	t_light		*lights;
	t_object	*objects;
}	t_scene;

#endif
