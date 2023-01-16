/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:09:46 by eshakhge          #+#    #+#             */
/*   Updated: 2022/09/21 17:09:51 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_down(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view + 180, vector, id,
			get_quardrant(player.view + 180)) > Size / 5 + Step)
	{
		player.y += Step * sin(player.view / 180 * M_PI);
		player.x -= Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_up(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view, vector, id,
			get_quardrant(player.view)) > Size / 5 + Step)
	{
		player.y -= Step * sin(player.view / 180 * M_PI);
		player.x += Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_left(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view + 90, vector, id,
			get_quardrant(player.view + 90)) > Size / 5 + Step)
	{
		player.x -= Step * sin(player.view / 180 * M_PI);
		player.y -= Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_right(void)
{
	t_pos	vector[2];
	int		id[2];

	vector[0].x = 0;
	vector[0].y = 0;
	vector[1].x = 0;
	vector[1].y = 0;
	id[0] = 0;
	id[1] = 0;
	if (check_wall_distance(player.view - 90, vector, id,
			get_quardrant(player.view - 90)) > Size / 5 + Step)
	{
		player.x += Step * sin(player.view / 180 * M_PI);
		player.y += Step * cos(player.view / 180 * M_PI);
		get_img(1);
		return (1);
	}
	return (0);
}

int	key_hook_press(int keycode, t_keys *keys)
{
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		keys->key_view_left = 1;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		keys->key_down = 1;
	else if (keycode == KEY_RIGHT || keycode == KEY_E)
		keys->key_view_right = 1;
	else if (keycode == KEY_UP || keycode == KEY_W)
		keys->key_up = 1;
	else if (keycode == KEY_A)
		keys->key_left = 1;
	else if (keycode == KEY_D)
		keys->key_right = 1;
	else if (keycode == KEY_ESC)
		close_prog();
	return (0);
}

int	key_hook_release(int keycode, t_keys *keys)
{
	if (keycode == KEY_LEFT || keycode == KEY_Q)
		keys->key_view_left = 0;
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		keys->key_down = 0;
	else if (keycode == KEY_RIGHT || keycode == KEY_E)
		keys->key_view_right = 0;
	else if (keycode == KEY_UP || keycode == KEY_W)
		keys->key_up = 0;
	else if (keycode == KEY_A)
		keys->key_left = 0;
	else if (keycode == KEY_D)
		keys->key_right = 0;
	else if (keycode == KEY_ESC)
		close_prog();
	return (0);
}

void	key_make(t_keys *keys)
{
	if (keys->key_view_left && key_view_left())
		;
	if (keys->key_down && key_down())
		;
	if (keys->key_view_right && key_view_right())
		;
	if (keys->key_up && key_up())
		;
	if (keys->key_left && key_left())
		;
	if (keys->key_right && key_right())
		;
}