/*
** ia.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src/my_ia
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Fri Feb 24 09:44:59 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:08:48 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

int	check_nbr_y(char **map)
{
  int	axe[2];
  int	nbr_y_stick;
  int	len_y;

  len_y = 0;
  nbr_y_stick = 0;
  axe[0] = 1;
  while (map[len_y] != NULL)
    len_y++;
  while (axe[0] != len_y)
    {
      if (check_y_next(map, axe) == 1)
	nbr_y_stick++;
      axe[0]++;
    }
  return (nbr_y_stick);
}

int	check_stick_nbr(char **map)
{
  int	x;
  int	y;
  int	stick;

  y = 0;
  stick = 0;
  while (map[y] != NULL)
    {
      x = 0;
      while (map[y][x] != '\0')
	{
	  if (map[y][x] == '|')
	    stick++;
	  x++;
	}
      y++;
    }
  return (stick);
}

int	check_size_line(char **map, int *y_x)
{
  int	x;
  int	len_x;
  int	nbr_stick;

  x = 1;
  len_x = 0;
  nbr_stick = 0;
  while (map[y_x[0]][len_x] != '\0')
    len_x++;
  while (x != (len_x - 1))
    {
      if (map[y_x[0]][x] == '|')
	{
	  nbr_stick++;
	  y_x[1] = x;
	}
      x++;
    }
  return (nbr_stick);
}

int	place_axe(char **map, int *axe)
{
  int	y_max;
  int	y_x[2];
  int	nbr[2];

  y_max = 0;
  init_my_counts(nbr, 2);
  init_my_counts(y_x, 2);
  y_x[0] = 1;
  while (map[y_max] != NULL)
    y_max++;
  while (y_x[0] != (y_max - 1))
    {
      nbr[0] = check_size_line(map, y_x);
      if (nbr[1] < nbr[0])
	{
	  nbr[1] = nbr[0];
	  axe[0] = y_x[0];
	  axe[1] = y_x[1];
	}
      y_x[0]++;
    }
  return (nbr[1]);
}

char	**the_ia(char **map, int max)
{
  int	nbr_stick[2];
  int	axe[3];
  int	modulo_y;

  init_my_counts(nbr_stick, 2);
  nbr_stick[0] = check_stick_nbr(map);
  nbr_stick[1] = place_axe(map, axe);
  modulo_y = check_nbr_y(map);
  if (modulo_y > 4 && (modulo_y %2) == 0)
    axe[2] = 0;
  else if (modulo_y == 4)
    {
      nbr_stick[1] = place_axe_other(map, axe, nbr_stick[1]);
      axe[2] = 0;
    }
  map = remove_stick_ia(map, max, nbr_stick, axe);
  return (map);
}
