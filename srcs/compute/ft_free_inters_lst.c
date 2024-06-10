/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_inters_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:55:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/06/10 14:55:56 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compute.h"

void	ft_free_inters_lst(t_inters *inters)
{
	t_inters	*next;

	while (inters)
	{
		next = inters->next;
		free(inters);
		inters = next;
	}
}
