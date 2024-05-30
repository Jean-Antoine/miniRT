/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:58:26 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/30 12:59:23 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>

static int	ft_check_suffix(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len > 3
		&& ft_strncmp(&file_name[len - 3], ".rt", 3) == 0)
		return (EXIT_SUCCESS);
	ft_putstr_fd("Error\nFile extension must be .rt\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	ft_open_file(char *file_name)
{
	int	fd;

	if (ft_check_suffix(file_name))
		return (-1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Reading file", TRUE);
	return (fd);
}
