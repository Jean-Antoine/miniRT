/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:53:37 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/05 17:20:49 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_parse_sp(char **args, t_object *dest)
{
	int	ac;

	ac = ft_tabsize(args);
	if (ac != 3 && ac != 4)
		return (ft_error("wrong number of parameters", FALSE));
	dest->type = sphere;
	return (ft_set_point(&dest->position, args[0])
		|| ft_set_scalar(&dest->diameter, args[1])
		|| ft_set_color(&dest->material.color, args[2])
		|| (ac == 4 && ft_set_material(&dest->material, args[3])));
}

static int	ft_parse_pl(char **args, t_object *dest)
{
	int	ac;

	ac = ft_tabsize(args);
	if (ac != 3 && ac != 4)
		return (ft_error("wrong number of parameters", FALSE));
	dest->type = plane;
	return (ft_set_point(&dest->position, args[0])
		|| ft_set_vector(&dest->direction, args[1])
		|| ft_set_color(&dest->material.color, args[2])
		|| (ac == 4 && ft_set_material(&dest->material, args[3])));
}

static int	ft_parse_cy(char **args, t_object *dest, t_bool is_cone)
{
	int	ac;

	ac = ft_tabsize(args);
	if (ac != 5 && ac != 6)
		return (ft_error("wrong number of parameters", FALSE));
	dest->type = cylinder;
	if (is_cone)
		dest->type = cone;
	return (ft_set_point(&dest->position, args[0])
		|| ft_set_vector(&dest->direction, args[1])
		|| ft_set_scalar(&dest->diameter, args[2])
		|| ft_set_scalar(&dest->height, args[3])
		|| ft_set_color(&dest->material.color, args[4])
		|| (ac == 6 && ft_set_material(&dest->material, args[5])));
}

static t_object	*ft_add_object(t_object **dest)
{
	t_object	*object;
	t_object	*last;

	object = ft_calloc(1, sizeof(t_object));
	if (!object)
		return (NULL);
	object->transform = ft_mat_id(4);
	object->material = ft_default_material();
	if (!*dest)
		*dest = object;
	else
	{
		last = *dest;
		while (last->next)
			last = last->next;
		last->next = object;
	}
	return (object);
}

int	ft_parse_object(char **args, t_object **dest)
{
	t_object	*object;

	if (ft_strcmp(args[0], "sp")
		&& ft_strcmp(args[0], "pl")
		&& ft_strcmp(args[0], "cy")
		&& ft_strcmp(args[0], "co"))
		return (2);
	object = ft_add_object(dest);
	if (!object)
		return (ft_error("ft_add_object", TRUE));
	if (!ft_strcmp(args[0], "sp"))
		return (ft_parse_sp(args + 1, object));
	if (!ft_strcmp(args[0], "pl"))
		return (ft_parse_pl(args + 1, object));
	if (!ft_strcmp(args[0], "cy") || !ft_strcmp(args[0], "co"))
		return (ft_parse_cy(args + 1, object, !ft_strcmp(args[0], "co")));
	return (EXIT_FAILURE);
}
