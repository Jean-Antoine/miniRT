/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:58:42 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/30 12:53:09 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

size_t	ft_tabsize(char	**tab)
{
	size_t	res;

	if (!tab)
		return (0);
	res = 0;
	while (tab[res])
		res++;
	return (res);
}
