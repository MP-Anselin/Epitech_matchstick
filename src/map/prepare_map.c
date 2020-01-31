/*
** prepare_map.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Thu Feb 16 18:07:01 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:07:24 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

char	**first_last_line(char **map, int line_stick, int star)
{
  int	y;
  int	x;

  y = 0;
  x = 0;
  while (map[y] != NULL)
    {
      map[y][0] = '*';
      while (x != star)
	{
	  if (y == 0 || y == (line_stick + 1) || x == (star - 1))
	    map[y][x] = '*';
	  else if (y != 0 && y != (line_stick + 1) && x != 0 && x != (star - 1))
	    map[y][x] = '|';
	  x++;
	}
      map[y][x] = '\0';
      x = 0;
      y++;
    }
  return (map);
}

char	**malloc_map(int line_stick, int star)
{
  char	**map;
  int	y;
  int	n;

  if ((map = malloc(sizeof(char*) * (line_stick + 3))) == NULL)
    return (NULL);
  n = line_stick + 3;
  y = 0;
  while (y != n)
    {
      map[y] = malloc(sizeof(char*) * (star + 1));
      y++;
    }
  map[y - 1] = NULL;
  return (map);
}

int	nbr_star(int line_stick)
{
  int	star;
  int	count;

  star = 3;
  count = 1;
  while (count != line_stick)
    {
      star += 2;
      count++;
    }
  return (star);
}

char	**prepare_map(int line_stick)
{
  int	star;
  char	**map;

  star = nbr_star(line_stick);
  if ((map = malloc_map(line_stick, star)) == NULL)
    return (NULL);
  map = first_last_line(map, line_stick, star);
  map = install_stick_lift(map, line_stick);
  map = install_stick_right(map, star, line_stick);
  return (map);
}
