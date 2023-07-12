/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:11:46 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/05 01:11:48 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_char(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x + 1])
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'E'
				&& map[y][x] != 'P' && map[y][x] != 'C')
				return (0);
		}
	}
	return (1);
}
