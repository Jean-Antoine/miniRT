/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/05/28 11:43:05 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	ft_error(char *str, t_bool use_errno)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (use_errno)
		perror(str);
	else
	{
		ft_putstr_fd("Invalid data: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}		
	return (EXIT_FAILURE);
}
