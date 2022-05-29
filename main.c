/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalmi <lasalmi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:14:30 by lasalmi           #+#    #+#             */
/*   Updated: 2022/05/29 09:13:15 by lasalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_usage(void)
{
	ft_putstr("Usage: ./fdf <filename>");
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_usage();
	ft_loadfile(*(argv + 1));
	return (0);
}