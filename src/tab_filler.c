/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:46:54 by njaber            #+#    #+#             */
/*   Updated: 2018/08/08 17:06:33 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_tab(t_data *d)
{
	t_dim	pos;
	t_dim	part;
	int		count;
	int		ret;

	part = (t_dim){0, 0};
	while (part.y < d->piece_size.y)
	{
		if (d->piece[part.y][part.x] == '*')
		{
			pos = (t_dim){0, 0};
			while (pos.y < d->board_size.y)
			{
				pos = (t_dim){(pos.x + 1) % d->board_size.x,
						pos.y + (pos.x + 1) / d->board_size.x};
			}
		}
		part = (t_dim){(part.x + 1) % d->piece_size.x,
			part.y + (part.x + 1) / d->piece_size.x};
	}
}
