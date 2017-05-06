/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 16:08:40 by oukrifa           #+#    #+#             */
/*   Updated: 2017/04/19 01:17:42 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
#define WRONG -1
#include "fillit.h"

static int		ft_char(char c)
{
	return (c == '.' || c == '#' || c == '\n' || c == '\0' ? TRUE : FALSE);
}

static int		ft_content(char *s)
{
	int i;
	int nb;
	int prev;

	i = -1;
	nb = 0;
	while (++i < 20 && nb < 3)
	{
		prev = nb;
		if (s[i] == '#')
		{
			if (i + 1 < 20 && s[i + 1] == '#')
				++nb;
			if (i + 5 < 20 && s[i + 5] == '#')
				++nb;
			if (prev == 2 && nb == 2)
				continue ;
			else if (prev == nb)
				return (FALSE);
		}
	}
	return (nb != 3 ? FALSE : TRUE);
}

static int		ft_count(char *str)
{
	int i;
	int n;

	n = 0;
	i = -1;
	while (++i < 20)
		if (str[i] == '#')
			++n;
	return (n == 4 ? TRUE : FALSE);
}

static int		ft_cl(char *str)
{
	int i;
	int line;
	int col;

	i = -1;
	line = 0;
	while (str[++i])
	{
		col = 0;
		if (!ft_char(str[i]))
			return (FALSE);
		while (str[i] && (str[i] == '.' || str[i] == '#'))
		{
			col++;
			i++;
		}
		line++;
		if (i >= 1 && str[i] == '\n' && str[i - 1] == '\n')
			continue ;
		if (str[i] == '\n' && col != 4)
			return (FALSE);
	}
	return (i == (int)ft_strlen(str) ? line : FALSE);
}

int				ft_check(char *s, char tab[26][4][4])
{
	int i;
	int n;

	i = -1;
	n = 0;
	if (((int)ft_strlen(s) != 20 && ((int)ft_strlen(s) - 20) % 21 != 0)
			|| ft_cl(s) % 5 != 4)
		return (WRONG);
	while (++i < (int)ft_strlen(s) && ++n)
	{
		if (ft_content(s + i) == FALSE || ft_count(s + i) == FALSE)
			return (WRONG);
		ft_stock_tetri(s + i, tab[n - 1], n - 1);
		i += 20;
		if (i < (int)ft_strlen(s) && s[i] != '\n')
			return (WRONG);
	}
	return (n);
}
