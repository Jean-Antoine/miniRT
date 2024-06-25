/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:52:08 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/25 14:51:22 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

t_inters	*ft_hit(t_inters **lst)
{
	t_inters	*inters;
	t_inters	*hit;

	if (!lst || !*lst)
		return (NULL);
	inters = *lst;
	hit = inters;
	while (inters->next)
	{
		inters = inters->next;
		if (inters->t >= TOLERANCE && (inters->t < hit->t || hit->t < 0))
			hit = inters;
	}
	if (hit->t < 0)
		return (NULL);
	return (hit);
}
