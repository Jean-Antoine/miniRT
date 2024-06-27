/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inters_addback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:14:53 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/06 14:52:11 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

static t_inters	*ft_create_inters(t_object *object, double t)
{
	t_inters	*inters;

	inters = ft_calloc(1, sizeof(t_inters));
	if (!inters)
	{
		ft_error("ft_create_intersection", TRUE);
		return (NULL);
	}
	inters->object = object;
	inters->t = t;
	return (inters);
}

static void	ft_inters_add_ordered(t_inters **lst, t_inters *new)
{
	t_inters	*inters;

	if (!lst)
		return ;
	inters = *lst;
	if (!inters)
	{
		*lst = new;
		return ;
	}
	if (inters->t > new->t)
	{
		*lst = new;
		new->next = inters;
		return ;
	}
	while (inters->next && inters->t < new->t)
		inters = inters->next;
	new->next = inters->next;
	inters->next = new;
}

void	ft_prepare_computations(t_ray ray, t_inters *inters)
{

	inters->comp.point = ft_position(ray, inters->t);
	inters->comp.eye_v = ft_v_scalar_prod(-1, ray.direction);//ft_v_normalize(ft_p_to_v(ray.origin, inters->comp.point));
	inters->comp.normal_v = ft_normal_at(inters->object, inters->comp.point);
	inters->comp.inside = FALSE;
	if (inters->object->type == sphere && ft_v_dot_prod(inters->comp.normal_v, inters->comp.eye_v) < 0)// vrai pour les spheres uniquement ?
	{
		inters->comp.inside = TRUE;
		inters->comp.normal_v = ft_v_scalar_prod(-1, inters->comp.normal_v);
	}
}

int	ft_new_inters(t_ray *ray, t_object *object, double t)
{
	t_inters	*new_inters;

	new_inters = ft_create_inters(object, t);
	if (!new_inters)
		return (EXIT_FAILURE);
	ft_inters_add_ordered(&ray->inters_lst, new_inters);
	ft_prepare_computations(*ray, new_inters);
	return (EXIT_SUCCESS);
}
