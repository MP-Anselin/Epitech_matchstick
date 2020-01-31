/*
** next_ia.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src/my_ia
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Feb 26 09:57:46 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:09:32 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

char	**stick_peer_next(char **map, int max, int *nbr_stick, int *axe)
{
  int	count;
  int	save;
  int	memory;

  count = 0;
  save = nbr_stick[1];
  if ((save % 2) == 0 && save != 1)
    save--;
  memory = save;
  while (count != save)
    {
      map[axe[0]][axe[1]] = ' ';
      axe[1]--;
      count++;
    }
  my_printf("AI removed %d match(es) from line %d\n", memory, axe[0]);
  return (map);
}

char	**stick_peer(char **map, int max, int *nbr_stick, int *axe)
{
  int	count;
  int	save;

  count = 0;
  if (nbr_stick[1] >= max)
    {
      if ((max %2) == 0 && max != 1)
	max--;
      save = max;
      while (count != max)
	{
	  map[axe[0]][axe[1]] = ' ';
	  axe[1]--;
	  count++;
	}
      my_printf("AI removed %d match(es) from line %d\n", save, axe[0]);
    }
  else if (nbr_stick[1] <= max)
    map = stick_peer_next(map, max, nbr_stick, axe);
  return (map);
}

char	**stick_odd_next(char **map, int max, int *nbr_stick, int *axe)
{
  int	count;
  int	save;
  int	memory;

  count = 0;
  save = nbr_stick[1];
  if ((save % 2) != 0 && save != 1)
    save--;
  memory = save;
  while (count != save)
    {
      map[axe[0]][axe[1]] = ' ';
      axe[1]--;
      count++;
    }
  my_printf("AI removed %d match(es) from line %d\n", memory, axe[0]);
  return (map);
}

char	**stick_odd(char **map, int max, int *nbr_stick, int *axe)
{
  int	count;
  int	save;

  count = 0;
  if (nbr_stick[1] >= max)
    {
      if ((max %2) != 0 && max != 1)
	max--;
      save = max;
      while (count != max)
	{
	  map[axe[0]][axe[1]] = ' ';
	  axe[1]--;
	  count++;
	}
      my_printf("AI removed %d match(es) from line %d\n", save, axe[0]);
    }
  else if (nbr_stick[1] <= max)
    map = stick_odd_next(map, max, nbr_stick, axe);
  return (map);
}
