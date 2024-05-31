/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:32:20 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/31 18:10:39 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_H
# define COMPUTE_H
# include "parsing.h"
# include "vector.h"
# define SIZE_X 800
# define SIZE_Y 450

typedef struct s_ray
{
	t_point			origin;
	t_vector		direction;
}	t_ray;

typedef struct s_inters
{
	t_object			*object;
	double				t;
	struct s_inters	*next;
}	t_inters;


int	ft_compute(t_scene *scene, int canvas[SIZE_X][SIZE_Y]);
int	ft_intersect_sphere(t_inters **inters_lst, t_object *sphere, t_ray ray);
t_ray	ft_create_ray(t_point origin, t_vector direction);



#endif