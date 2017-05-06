/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 14:04:38 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/20 14:04:46 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_stock_tetri(char *s, char tab[4][4], int pos)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while (++i < 4 && k < 20)
	{
		j = -1;
		while (++j < 4)
		{
			if (s[k] == '.')
				tab[i][j] = '.';
			else if (s[k] == '#')
				tab[i][j] = 'A' + pos;
			if (k + 1 == 4 || k + 1 == 9 || k + 1 == 14)
				++k;
			++k;
		}
		tab[i][j] = '\0';
	}
	ft_up_left(tab);
}
