/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 09:46:49 by madams            #+#    #+#             */
/*   Updated: 2019/09/14 10:26:58 by madams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "wolf3d.h"

/*
** Print "How to Use" instructions.
*/

void	print_menu(t_wolf3d *wolf3d)
{
	int y;
	void *mlx;
	void *win;

	y = 0;

	mlx = wolf3d->mlx;
	win = wolf3d->mlx;

	mlx_string_put(mlx, win, 65, y += 20, 0xfafafa, "How to Use Wolf3d");
	mlx_string_put(mlx, win, 65, y += 35, 0xfafafa, "Exit Wolf3d: ESC");
	mlx_string_put(mlx, win, 15, y += 35, 0xfafafa, "Move: WASD or Arrows");

}
