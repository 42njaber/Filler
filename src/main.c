/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:54:24 by njaber            #+#    #+#             */
/*   Updated: 2018/08/08 16:03:35 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int						log_fd;

static void		free_piece(t_data *d)
{
	int		i;

	i = -1;
	while (++i < d->piece_size.y)
		free(d->piece[i]);
	free(d->piece);
}

static void		line_router(t_data *d, char **line)
{
	if (d->state == START)
	{
		parse_first_line(d, line);
		dprintf(log_fd, "Parsed first line\n");
		d->state = BOARD;
	}
	else if (d->state == BOARD)
	{
		parse_board(d, line);
		dprintf(log_fd, "Parsed board\n");
		d->state = PIECE;
	}
	else if (d->state == PIECE)
	{
		parse_piece(d, line);
		dprintf(log_fd, "Parsed piece\n");
		place_piece(d);
		free_piece(d);
		d->state = BOARD;
	}
}

int		main(void)
{
	t_data	d;
	int		ret;
	char	*line;

	ft_bzero(&d, sizeof(d));
	if ((log_fd = open("log.txt", O_CREAT | O_RDWR)) == 0)
		ft_error("Couldn't open log file\n");
	while ((ret = get_next_line(0, &line)) == 1)
	{
		line_router(&d, &line);
		free(line);
	}
}
