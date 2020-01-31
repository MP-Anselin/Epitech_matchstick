/*
** others_fonction.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src/my_ia
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sat Feb 25 19:10:30 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:09:58 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

void	init_my_counts(int *nbr, int var)
{
  int	i;

  i = 0;
  while (i != var)
    nbr[i++] = 0;
}

int	check_y_next(char **map, int *axe)
{
  axe[1] = 0;
  while (map[axe[0]][axe[1]] != '\0')
    {
      if (map[axe[0]][axe[1]] == '|')
	return (1);
      axe[1]++;
    }
  return (0);
}

int	place_axe_other(char **map, int *axe, int len)
{
  int	y_max;
  int	y_x[2];
  int	nbr[2];

  y_max = 0;
  init_my_counts(nbr, 2);
  nbr[1] = len;
  init_my_counts(y_x, 2);
  y_x[0] = 1;
  while (map[y_max] != NULL)
    y_max++;
  while (y_x[0] != (y_max - 1))
    {
      nbr[0] = check_size_line(map, y_x);
      if (nbr[1] > nbr[0] && nbr[0] != 0)
	{
	  nbr[1] = nbr[0];
	  axe[0] = y_x[0];
	  axe[1] = y_x[1];
	}
      y_x[0]++;
    }
  return (nbr[1]);
}
