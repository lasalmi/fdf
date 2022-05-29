/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileloader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:59:31 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/29 10:37:50 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *error)
{
	ft_putstr(error);
	exit(1);
}

size_t	ft_countnbrs(char *str)
{
	size_t	nbrs;
	char	*duplicate;
	char	*to_free;

	duplicate = ft_strdup(str);
	if (!duplicate)
		ft_error("Malloc failed.");
	to_free = duplicate;
	nbrs = 0;
	while (ft_getnbrs(&duplicate))
		nbrs++;
	free(to_free);
	return (nbrs);
}

static void loadrow(char *row, int **table, size_t nbrs)
{
	if (ft_countnbrs(row) != nbrs)
		ft_error("Invalid file");
	*table = (int *)malloc(sizeof(int) * nbrs);
	if (!table)
		ft_error("Malloc failed.");
	while (nbrs--)
	{
		**table = ft_atoi(ft_getnbrs(&row));
		*table = *table + 1;
	}
}

static void loadvalues(int fd, int **table)
{
	size_t	numbers;
	int		ret;
	char	*line;
	char	*to_free;

	ret = get_next_line(fd, &line);
	numbers = ft_countnbrs(line);
	if (ret < 1 || numbers == 0)
		ft_error("Invalid file.");
	while (ret > 0)
	{
		to_free = line;
		loadrow(line, table, numbers);
		free(to_free);
		ret = get_next_line(fd, &line);
	}
}

int	**ft_loadfile(char *file)
{
	int 	fd;
	int		**table;
	char 	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error opening file!");
	table = (int **)malloc(sizeof(int **) * ft_filerows(file));
	if (!table)
		ft_error("Malloc failed.");
	loadvalues(fd, table);
}