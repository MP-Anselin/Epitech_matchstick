/*
** my_matchstick.h for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/include
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Feb 14 14:27:18 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:11:30 2017 Anselin Mackendy-pierre
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"get_next_line.h"

#ifndef		_MATCHSTICK_H_
# define	_MATCHSTICK_H_

int	arg_line(int line_stick);
int	arg_matches(int line, char **map, int line_stick, int max);
int	check_var(int var, int line_stick, int nbr);
int	check_arg(char *stock, int line_stick, int nbr);
int	check_line_nbr_stick(int var, int line, char **map, int max);
int	check_stick_nbr(char **map);
int	check_size_line(char **map, int *x_save);
int	check_av(char **av);
int	check_y_next(char **map, int *axe);
char	**first_last_line(char **map, int line_stick, int star);
int	game_play(char **map, int max, int line_stick);
char	**install_stick_right(char **map, int line, int len);
char	**install_stick_lift(char **map, int len);
int	if_win(char **map, int nbr);
void	init_my_counts(int *nbr, int var);
char	**malloc_map(int line_stick, int star);
int	my_printf(const char *format, ...);
void	my_putstrstr(char **str);
int	my_getnbr(char *av);
int	main(int ac, char **av);
int	nbr_star(int line_stick);
char	**prepare_map(int line_stick);
int	place_axe(char **map, int *axe);
int	place_axe_other(char **map, int *axe, int len);
char	**remove_stick(char **map, int line, int matc, int max);
char	**remove_stick_ia(char **map, int max, int *nbr_stick, int *axe);
char	**the_player(char **map, int max, int line_stick);
char	**the_ia(char **map, int max);
char	**stick_odd(char **map, int max, int *nbr_stick, int *axe);
char	**stick_odd_next(char **map, int max, int *nbr_stick, int *axe);
char	**stick_peer(char **map, int max, int *nbr_stick, int *axe);
char	**stick_peer_next(char **map, int max, int *nbr_stick, int *axe);

#endif	/* !MATCHSTICK_H_ */
