/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 08:39:28 by madams            #+#    #+#             */
/*   Updated: 2019/09/14 10:35:44 by madams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	help_text(t_wolf3d *t)
{
	mlx_string_put(t->mlx, t->win, 10, 10,
			0xfafafa, "Press W A S D or the arrow keys to move.");
	mlx_string_put(t->mlx, t->win, 10, 30, 0xfafafa, "Press SHIFT to sprint.");
	mlx_string_put(t->mlx, t->win, 10, 50,
			0xfafafa, "Press DEL to reset the level.");
	mlx_string_put(t->mlx, t->win, 10, 90,
			0xfafafa, "Press H to show or hide this help.");
	mlx_string_put(t->mlx, t->win, 10, 110,
			0xfafafa, "Press ESC to quit.");
}
