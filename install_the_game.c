/*
** install_the_game.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Feb 14 11:14:22 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:26:23 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

char	**remove_stick(char **map, int line, int matc, int max)
{
  int	y_max;
  int	x_max;
  int	x;
  int	count;

  x_max = 1;
  y_max = 1;
  count = 0;
  while (map[y_max] != NULL)
    y_max++;
  while (map[1][x_max] != '*')
    x_max++;
  x = x_max;
  if (line < 1 && line > y_max - 1)
    return (NULL);
  while (map[line][x] != '|')
    x--;
  while (count != matc)
    {
      if (map[line][x] == '|')
	map[line][x] = ' ';
      count++;
      x--;
    }
  return (map);
}

char	**the_player(char **map, int max, int line_stick)
{
  char	*l;
  char	*m;
  int	line;
  int	matc;

  my_printf("\nYour turn:\n");
  my_printf("Line: ");
  if ((line = arg_line(line_stick)) == -2)
    return (NULL);
  my_printf("Matches: ");
  if ((matc = arg_matches(line, map, line_stick, max)) == -2)
    return (NULL);
  my_printf("Player removed %d match(es) from line %d\n", matc, line);
  if (remove_stick(map, line, matc, max) == NULL)
    return (NULL);
  return (map);
}

int	game_play(char **map, int max, int line_stick)
{
  my_putstrstr(map);
  while (42)
    {
      if ((map = the_player(map, max, line_stick)) == NULL)
	return (-1);
      my_putstrstr(map);
      if (if_win(map, 0) == 1)
	return (2);
      my_printf("\nAI's turn...\n");
      map = the_ia(map, max);
      my_putstrstr(map);
      if (if_win(map, 1) == 2)
	return (1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	line_stick;
  int	max;
  int	game;
  char	**map;

  if (ac != 3)
    return (84);
  if (check_av(av) == 1)
    return (84);
  line_stick = my_getnbr(av[1]);
  max = my_getnbr(av[2]);
  if ((map = prepare_map(line_stick)) == NULL)
    return (84);
  if ((game = game_play(map, max, line_stick)) == -1)
    {
      my_printf("\n");
      return (0);
    }
  if (game == 2)
    return (2);
  else if (game == 1)
    return (1);
  return (0);
}
