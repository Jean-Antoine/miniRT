/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:58:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/24 14:58:43 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_check_suffix(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len > 3
		&& ft_strncmp(&file_name[len - 3], ".rt", 3) == 0)
		return (OK);
	ft_putstr_fd("Error : file suffix must be .rt\n", 2);
	return (KO);
}

int	ft_open_file(char *file_name)
{
	int	fd;

	if (ft_check_suffix(file_name) == KO)
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		perror(file_name);
	return (fd);
}
