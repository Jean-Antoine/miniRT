/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:53:37 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/28 12:35:48 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_parse_sp(char **args, t_object *dest)
{
	if (ft_tabsize(args) != 3)
		return (ft_error("wrong number of parameters", FALSE));
	dest->type = sphere;
	return (ft_set_point(&dest->position, args[0])
		|| ft_set_scalar(&dest->diameter, args[1])
		|| ft_set_color(&dest->color, args[2]));
}

static int	ft_parse_pl(char **args, t_object *dest)
{
	if (ft_tabsize(args) != 3)
		return (ft_error("wrong number of parameters", FALSE));
	dest->type = plan;
	return (ft_set_point(&dest->position, args[0])
		|| ft_set_vector(&dest->direction, args[1])
		|| ft_set_color(&dest->color, args[2]));
}

static int	ft_parse_cy(char **args, t_object *dest)
{
	if (ft_tabsize(args) != 5)
		return (ft_error("wrong number of parameters", FALSE));
	dest->type = cylinder;
	return (ft_set_point(&dest->position, args[0])
		|| ft_set_vector(&dest->direction, args[1])
		|| ft_set_scalar(&dest->diameter, args[2])
		|| ft_set_scalar(&dest->height, args[3])
		|| ft_set_color(&dest->color, args[4]));
		
}

static t_object	*ft_add_object(t_object **dest)
{
	t_object	*object;
	t_object	*last;

	object = ft_calloc(1, sizeof(t_object));
	if (!object)
		return (NULL);
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
		&& ft_strcmp(args[0], "cy"))
		return (2);
	object = ft_add_object(dest);
	if (!object)
		return (ft_error("ft_add_object", TRUE));
	if (!ft_strcmp(args[0], "sp"))
		return (ft_parse_sp(args + 1, object));
	if (!ft_strcmp(args[0], "pl"))
		return (ft_parse_pl(args + 1, object));
	if (!ft_strcmp(args[0], "cy"))
		return (ft_parse_cy(args + 1, object));
	return (EXIT_FAILURE);
}