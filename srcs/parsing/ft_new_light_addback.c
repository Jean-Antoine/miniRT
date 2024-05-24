/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_light_addback.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:38 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 18:05:00 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_light	*ft_new_light_addback(t_light **light_lst)
{
	t_light	*new_light;
	t_light	*last;

	new_light = ft_calloc(1, sizeof(t_light));
	if (!new_light)
	{
		perror("malloc");
		return (NULL);
	}
	if (!*light_lst)
		*light_lst = new_light;
	else 
	{
		last = *light_lst;
		while (last->next)
			last = last->next;
		last->next = new_light;
	}
	return (new_light);
}
