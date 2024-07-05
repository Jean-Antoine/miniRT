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

static void	ft_insert(t_inters *new, t_inters *inters)
{
	while (inters)
	{
		if (!inters->next)
			break ;
		if (inters->t < new->t
			&& new->t < inters->next->t)
			break ;
		inters = inters->next;
	}
	new->next = inters->next;
	inters->next = new;
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
	ft_insert(new, inters);
}

int	ft_add_inters(t_ray *ray, t_object *object, double t)
{
	t_inters	*new_inters;
	
	// if (t < TOLERANCE)
	// 	return (EXIT_SUCCESS);
	new_inters = ft_create_inters(object, t);
	if (!new_inters)
		return (EXIT_FAILURE);
	ft_inters_add_ordered(&ray->inters_lst, new_inters);
	return (EXIT_SUCCESS);
}
