/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:04:33 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/05/27 16:00:06 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	ft_args_to_scene(char **args, t_scene *scene)
{
	if (!args || !args[0])
		return (EXIT_SUCCESS);
	if (ft_strcmp(args[0], "A") == 0)
		return (ft_create_ambiant_light(args, scene));
	if (ft_strcmp(args[0], "L") == 0)
		return (ft_create_spot_light(args, scene));
	ft_putstr_fd("Error: invalid data in file\n", 2);
	return (EXIT_FAILURE);
}

int	ft_parse_line(char *line, t_scene *scene)
{
	char	**args;

	if (!line)
		return (EXIT_FAILURE);
	if (!ft_strcmp(line, "\n"))
		return (EXIT_SUCCESS);
	line[ft_strlen(line) - 1] = 0;
	args = ft_split(line, ' ');
	if (!args)
	{
		perror("ft_split");
		return (EXIT_FAILURE);
	}
	if (ft_args_to_scene(args, scene) == EXIT_FAILURE)
	{
		ft_free_tab((void **)args);
		return (EXIT_FAILURE);
	}
	ft_free_tab((void **)args);
	return (EXIT_SUCCESS);
}
