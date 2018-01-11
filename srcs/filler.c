/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 22:33:44 by ibohonos          #+#    #+#             */
/*   Updated: 2018/01/11 12:15:12 by ibohonos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		ft_strdel(&arr[i++]);
	free(arr);
	arr = NULL;
}

int		ft_len_btw(int i, int j, t_map *p)
{
	int k;
	int z;

	k = p->save_x - i;
	z = p->save_y - j;
	k *= k;
	z *= z;
	k += z;
	return (k);
}

int		ft_find_spase(t_map *p, int i, int j)
{
	int k;

	k = 0;
	if ((i - 2) >= 0 && p->map[i - 1][j] == '.' && p->map[i - 2][j] == '.')
		k++;
	if ((i + 2) < p->h && p->map[i + 1][j] == '.' && p->map[i + 2][j] == '.')
		k++;
	if ((j - 2) >= 0 && p->map[i][j - 1] == '.' && p->map[i][j - 2] == '.')
		k++;
	if ((j + 2) < p->w && p->map[i][j + 1] == '.' && p->map[i][j + 2] == '.')
		k++;
	if (k >= 2)
		return (1);
	return (0);
}

int		ft_len(t_map *p)
{
	int		i;
	int		j;
	char	letter;

	if (p->player == 'O')
		letter = 'X';
	else
		letter = 'O';
	i = 0;
	while (i < p->h)
	{
		j = 0;
		while (j < p->w)
		{
			if (p->map[i][j] == letter && ft_find_spase(p, i, j))
			{
				p->save_x = j;
				p->save_y = i;
				return (1);
			}
		}
	}
	return (0);
}

int		ft_check_place(t_map *p, int x, int y, char letter)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	if ((p->w - x - p->x) < 0 || (p->h - y - p->y) < 0)
		return (0);
	while (k < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			if (e->map[y + k][x + j] == letter && p->tetri[k][j] == '*')
				i++;
			else if (p->map[y + k][x + j] != '.' && p->tetri[k][j] == '*')
				i = 2;
			j++;
		}
		k++;
	}
	if (i == 1)
		return (1);
	return (0);
}

void	ft_find_place(t_map *p, int *a, int *b)
{
	int		x;
	int		y;
	char	letter;

	if (p->player == 'O')
		letter = p->player;
	else
		letter = 'X';
	y = 0;
	while (y < p->h)
	{
		x = 0;
		while (x < p->w)
		{
			if (ft_check_place(p, x, y, letter))
			{
				if (((*a) == 0 && (*b) == 0) || (ft_len(p) &&
				ft_len_btw((*a), (*b), p) > ft_len_btw(i, j, p)))
				{
					(*a) = y;
					(*b) = x;
				}
			}
		}
	}
}

void	ft_place_map(t_map *p)
{
	char	tmp;
	int		a;
	int		b;

	a = 0;
	b = 0;
	ft_find_place(p, &a, &b);
}

void	ft_place_line_tetri(char *line, t_map *p)
{
	p->tetri[p->row] = ft_strdup(line);
	p->row++;
	if (p->row == p->y)
	{
		p->row = 0;
		p->done = 1;
	}
}

void	ft_place_line_map(char *line, t_map *p)
{
	char	**arr;

	arr = ft_strsplit(s, ' ');
	if (arr[1] && !(ft_strcmp(arr[0], "Plateau") == 0))
	{
		p->map[p->row] = ft_strdup(arr[1]);
		p->row++;
	}
	ft_free_arr(arr);
}

void	ft_find_tetri(char *line, t_map *p)
{
	char **tmp;

	tmp = ft_strsplit(line, ' ');
	if (ft_strcmp(tmp[0], "Piece") == 0)
	{
		p->x = ft_atoi(tmp[2]);
		p->y = ft_atoi(tmp[1]);
		p->tetri = (char **)malloc(sizeof(char *) * p->y + 1);
		p->row = 0;
	}
	ft_free_arr(tmp);
}

void	ft_find_map(char *line, t_map *p)
{
	char **tmp;

	tmp = ft_strsplit(line, ' ');
	if (ft_strcmp(tmp[0], "Plateau") == 0)
	{
		p->w = ft_atoi(tmp[2]);
		p->h = ft_atoi(tmp[1]);
		p->map = (char **)malloc(sizeof(char *) * p->h + 1);
		p->row = 0;
	}
	ft_free_arr(tmp);
}

void	ft_find_player(char *line, t_map *p)
{
	if (line[10] == '1')
		p->player = 'O';
	else if (line[10] == '2')
		p->player = 'X';
}

void	ft_init_map(t_map *p)
{
	p->player = 0;
	p->x = 0;
	p->y = 0;
	p->w = 0;
	p->h = 0;
	p->row = -1;
	p->done = 0;
	p->save_x = 0;
	p->save_y = 0;
	p->map = NULL;
	p->tetri = NULL;
}

void	filler(char *line, t_map *p)
{
	ft_init_map(p);
	while (get_next_line(0, &line) > 0)
	{
		if (!p->player)
			ft_find_player(line, p);
		if (!p->w && !p->h)
			ft_find_map(line, p);
		else if (p->row >= 0 && p->row < p->h)
			ft_place_line_map(line, p);
		if (p->row >= p->h)
			ft_find_tetri(line, p);
		else if (!p->flag && p->row >= 0 && p->row < y)
			ft_place_line_tetri(line, p);
		if (p->done == 1);
			ft_place_map(p);
		ft_strdel(&line);
	}
}
