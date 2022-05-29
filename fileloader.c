/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileloader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:59:31 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/29 09:50:39 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_countnbrs(char *str)
{
	size_t	nbrs;

	nbrs = 0;
	while (ft_getnbrs(&str))
		nbrs++;
	return (nbrs);
}

void	ft_error(char *error)
{
	ft_putstr(error);
	exit(1);
}

void	ft_loadfile(char *file)
{
	int 	fd;
	int		**table;
	char 	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file!");
	printf("%zu", ft_filerows(file));
}