
#ifndef FILLER_H
# define FILLER_H

# define BUF_SIZE 4096

enum			e_state {
	START,
	BOARD,
	PIECE,
	OTHER
};

typedef struct	s_dim {
	int		x;
	int		y;
}				t_dim;

typedef struct	s_data {
	int		state;
	int		player;
	char	*str;
	t_dim	bsz;
	t_dim	psz;
	t_dim	piece_pos;
	char	**board;
	char	**piece;
	int		**pos_tab;
}				t_data;

void			parse_first_line(t_data *d, char **line);
void			parse_board(t_data *d, char **line);
void			parse_piece(t_data *d, char **line);

void			place_piece(t_data *d);

void		fill_tab(t_data *d);

#endif
