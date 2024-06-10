/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:44:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/06/10 14:30:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_mat_obj(t_object *list)
{
	while (list)
	{
		if (list->type == sphere)
			ft_mat_sphere(list);
		list = list->next;
	}
}
