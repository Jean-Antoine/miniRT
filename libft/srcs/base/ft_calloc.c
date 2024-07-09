/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:10:52 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/09 16:00:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "time.h"
#include "errno.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*out;
	static int	boundary;
	static int	x = 0;

	if (x == 0)
	{
		srand(time(NULL));
		boundary = rand() % 1000;
		errno = 12;
	}		
	if (++x > boundary)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return ((void *)malloc(0));
	if (nmemb > ((size_t)(-1)) / size)
		return (NULL);
	out = (void *)malloc(nmemb * size);
	if (!out)
		return (NULL);
	ft_bzero(out, nmemb * size);
	return (out);
}
