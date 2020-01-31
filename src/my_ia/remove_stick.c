/*
** remove_stick.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src/my_ia
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Sun Feb 26 12:09:18 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:10:06 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

char	**remove_stick_ia(char **map, int max, int *nbr_stick, int *axe)
{
  if (axe[2] == 0)
    {
      if ((nbr_stick[0] %2) == 0)
	map = stick_peer(map, max, nbr_stick, axe);
      else if ((nbr_stick[0] %2) != 0)
	map = stick_odd(map, max, nbr_stick, axe);
    }
  else
    {
      if ((nbr_stick[0] %2) == 0)
	map = stick_peer(map, 1, nbr_stick, axe);
      else if ((nbr_stick[0] %2) != 0)
	map = stick_odd(map, 2, nbr_stick, axe);
    }
  return (map);
}

