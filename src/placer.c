/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:09:54 by njaber            #+#    #+#             */
/*   Updated: 2018/08/08 17:14:42 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"

static void		alloc_tab(t_data *d)
{
	int		i;

	d->pos_tab = (int**)ft_memalloc(sizeof(int*) * (d->board_size.y + d->piece_size.y - 1));
	i = -1;
	while (++i < d->board_size.y)
		d->pos_tab[i] = (int*)ft_memalloc(sizeof(int) * d->board_size.x);
}

static void		free_tab(t_data *d)
{
	int		i;

	i = -1;
	while (++i < d->board_size.y)
		free(d->pos_tab[i]);
	free(d->pos_tab);
}

void			place_piece(t_data *d)
{
	alloc_tab(d);
	fill_tab(d);
	d->piece_pos.x = 1;
	d->piece_pos.y = 1;
	free_tab(d);
	ft_printf("%d %d\n", d->pos.x, d->pos.y);
}
