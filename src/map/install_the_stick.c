/*
** install_the_stick.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Thu Feb 16 19:45:22 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:06:22 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

char	**install_stick_right(char **map, int len, int line)
{
  int	esp;
  int	count;
  int	y;
  int	x;

  y = line;
  esp = 0;
  count = 0;
  while (y > 0)
    {
      x = len - 2;
      while (x > 0)
	{
	  if (count != esp)
	    {
	      map[y][x] = ' ';
	      count++;
	    }
	  x--;
	}
      count = 0;
      esp++;
      y--;
    }
  return (map);
}

char	**install_stick_lift(char **map, int line)
{
  int	esp;
  int	count;
  int	y;
  int	x;

  y = line;
  esp = 0;
  count = 0;
  while (y > 0)
    {
      x = 0;
      while (map[y][x++] != '\0')
	{
	  if (count != esp)
	    {
	      map[y][x] = ' ';
	      count++;
	    }
	}
      count = 0;
      esp++;
      y--;
    }
  return (map);
}
