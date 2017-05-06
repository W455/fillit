/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 22:06:06 by snassour          #+#    #+#             */
/*   Updated: 2017/04/20 13:06:32 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_puterror(void)
{
	write(1, "error\n", 6);
	return (1);
}

static int		ft_putusage(void)
{
	write(1, "usage: ./fillit source_file\n", 28);
	return (1);
}

int				main(int ac, char **av)
{
	char	tab[26][4][4];
	char	**map;
	int		nb_tetri;
	int		size;
	char	*input;

	if (ac != 2)
		return (ft_putusage());
	if ((size = ft_open(av[1])) < 1)
		return (ft_puterror());
	if (!(input = ft_read(size)
		|| (nb_tetri = ft_check(input, tab)) == -1))
		return (ft_puterror());
	size = ft_sqrt(nb_tetri * 4);
	if (!(map = ft_sqmap_dotalloc(size)))
		return (1);
	while (!ft_finished(map, nb_tetri, tab, 0))
	{
		ft_free_map(map, size);
		if (!(map = ft_sqmap_dotalloc(++size)))
			return (1);
	}
	ft_print_map(map, size);
	ft_free_map(map, size);
	return (0);
}
