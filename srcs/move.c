/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:54:46 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/01 17:57:50 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move(t_game *g, t_player *pl, int x, int y, double f(double))
{
	int	posx;
	int	posy;

	posy = (int)f((double)pl->pos.y / SIZE) + (y * 8) / SIZE;
	posx = (int)f((double)pl->pos.x / SIZE) + (x * 8) / SIZE;
	if (pl->pos.x % SIZE == 0 && pl->pos.y % SIZE == 0
		&& g->map[posy][posx] != '1')
		g->moves++;
	if (g->map[posy][posx] == 'E' && g->item_left == 0)
		quit(g);
	if (g->map[posy][posx] == 'C')
	{
		g->item_left--;
		g->map[posy][posx] = '0';
	}
	if (g->map[posy][posx] != '1')
	{
		pl->pos.x += x;
		pl->pos.y += y;
		mlx_put_image_to_window(g->id, g->win, g->floor,
			pl->prev_pos.x, pl->prev_pos.y);
		mlx_put_image_to_window(g->id, g->win, g->player.img,
			pl->pos.x, pl->pos.y);
	}
}

static void	reset_dir(t_dir *dir, t_dir *next_dir)
{
	*dir = *next_dir;
	*next_dir = NONE;
}

void	change_pos(t_game *g, t_player *pl)
{
	if (pl->next_dir != NONE
		&& (pl->pos.x % SIZE == 0 && pl->pos.y % SIZE == 0))
		reset_dir(&pl->dir, &pl->next_dir);
	if (pl->dir == LEFT)
		move(g, pl, -SIZE / 8, 0, &ceil);
	else if (pl->dir == RIGHT)
		move(g, pl, SIZE / 8, 0, &floor);
	else if (pl->dir == TOP)
		move(g, pl, 0, -SIZE / 8, &ceil);
	else if (pl->dir == DOWN)
		move(g, pl, 0, SIZE / 8, &floor);
}
