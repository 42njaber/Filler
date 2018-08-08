/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 13:48:13 by njaber            #+#    #+#             */
/*   Updated: 2018/08/08 15:56:11 by njaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"
#   include <stdio.h>

extern int				log_fd;

void			parse_first_line(t_data *d, char **line)
{
	if (ft_strncmp(*line, "$$$ exec p", 10) != 0)
		ft_error("First line not well formated\n");
	d->player = line[0][10] - '0';
	dprintf(log_fd, "Player number : %d\n", d->player);
	if (d->player != 1 && d->player != 2)
		ft_error("Wrong player number\n");
}

static void		parse_board_size(t_data *d, char **line)
{
	int		i;

	if (ft_strncmp(*line, "Plateau ", 8) != 0)
		ft_error("Board description not well formated\n");
	d->board_size.y = ft_atoi(line[0] + 8);
	i = 9;
	while (ft_isdigit(line[0][i]))
		i++;
	d->board_size.x = ft_atoi(line[0] + i);
	dprintf(log_fd, "Board size: %d, %d\n", d->board_size.y, d->board_size.x);
	free(*line);
	if (d->board_size.x < 1 || d->board_size.y < 1)
		ft_error("Wrong board size\n");
	if ((d->board = (char**)ft_memalloc(sizeof(char*) *
					d->board_size.y)) == NULL)
		ft_error("Malloc error");
	i = -1;
	while (++i < d->board_size.y)
		d->board[i] = ft_strnew(d->board_size.x);
}

void			parse_board(t_data *d, char **line)
{
	int		i;

	if (d->board_size.x == 0)
		parse_board_size(d, line);
	if (get_next_line(0, line) != 1)
		ft_error("Error while reading board");
	i = -1;
	while (++i < d->board_size.y)
	{
		free(*line);
		if (get_next_line(0, line) != 1
				|| strlen(*line) != (size_t)(d->board_size.x + 4))
			ft_error("Error while reading board");
		ft_strcpy(d->board[i], line[0] + 4);
	}
	i = -1;
	while (++i < d->board_size.y)
		dprintf(log_fd, "%s\n", d->board[i]);
}

static void		parse_piece_size(t_data *d, char **line)
{
	int		i;

	if (ft_strncmp(*line, "Piece ", 6) != 0)
		ft_error("Piece description not well formated\n");
	d->piece_size.y = ft_atoi(line[0] + 6);
	i = 6;
	while (ft_isdigit(line[0][i]))
		i++;
	d->piece_size.x = ft_atoi(line[0] + i);
	dprintf(log_fd, "Piece size: %d, %d\n", d->piece_size.y, d->piece_size.x);
	if (d->piece_size.x < 1 || d->piece_size.y < 1)
		ft_error("Wrong piece size\n");
	if ((d->piece = (char**)ft_memalloc(sizeof(char*) *
					d->piece_size.y)) == NULL)
		ft_error("Malloc error");
	i = -1;
	while (++i < d->piece_size.y)
		if ((d->piece[i] = ft_strnew(d->piece_size.x)) == NULL)
			ft_error("Malloc error");
}

void			parse_piece(t_data *d, char **line)
{
	int		i;
	int		ret;

	parse_piece_size(d, line);
	i = -1;
	while (++i < d->piece_size.y)
	{
		free(*line);
		ret = get_next_line(0, line);
		if (ret < 1 || ft_strlen(*line) != (size_t)(d->piece_size.x))
			ft_error("Error while reading piece");
		ft_strcpy(d->piece[i], *line);
	}
	i = -1;
	while (++i < d->piece_size.y)
		dprintf(log_fd, "%s\n", d->piece[i]);
}
