/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 08:39:13 by madams            #+#    #+#             */
/*   Updated: 2019/09/12 13:19:50 by madams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	mlx_win_init(t_wolf3d *t)
{
	char	*title;

	title = ft_strjoin("Wolf3d : ", t->map_name);
	t->mlx = mlx_init();
	t->win = mlx_new_window(t->mlx, WINX, WINY, title);
	ft_strdel(&title);
}

void	wolf3d_init(t_wolf3d *t)
{
	t->x_pos = 3;
	t->y_pos = 3;
	t->x_dir = -1;
	t->y_dir = 0;
	t->x_plane = 0;
	t->y_plane = 0.66;
	t->ms = 0.05;
	t->rs = 0.05;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->x_text = 0;
	t->y_text = 0;
}

int		main(int ac, char **av)
{
	t_wolf3d *t;

	if (ac != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!(t = (t_wolf3d *)malloc(sizeof(t_wolf3d))))
		return (0);
	if (!(parser(t, av)))
		return (0);
	mlx_win_init(t);
	mlx_hook(t->win, 17, 0L, ft_close, t);
	mlx_hook(t->win, 2, (1L << 0), key_press, t);
	mlx_hook(t->win, 3, (1L << 1), key_release, t);
	t->help = 1;
	wolf3d_init(t);
	ray_casting(t);
	mlx_loop_hook(t->mlx, move, t);
	mlx_loop(t->mlx);
}
