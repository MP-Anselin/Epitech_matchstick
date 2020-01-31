/*
** fonction_basic.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick/src
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Tue Feb 14 14:35:42 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:29:38 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

int	check_av(char **av)
{
  int x;

  x = 0;
  if (av[2][0] == '0')
    return (84);
  while (av[2][x] != '\0')
    {
      if (av[2][x] < '0' || av[2][x] > '9')
	return (1);
      else
	x++;
    }
  return (0);
}

int	if_win(char **map, int nbr)
{
  int	stick;

  if (check_stick_nbr(map) == 0)
    {
      if (nbr == 1)
	{
	  my_printf("I lost... snif... but I'll get you next time\n");
	  return (2);
	}
      if (nbr == 0)
	{
	  my_printf("You lost, too bad...\n");
	  return (1);
	}
    }
  return (0);
}

void	my_putstrstr(char **str)
{
  int	y;

  y = 0;
  while (str[y] != NULL)
    {
      my_printf("%s\n", str[y]);
      y++;
    }
}

int	my_getnbr(char *av)
{
  int	nbr;
  int	neg;
  int	i;

  neg = 1;
  i = 0;
  nbr = 0;
  while (av[i] != '\0')
    {
      while ((av[i] >= '0' && av[i] <= '9') || av[i] == '-')
	{
	  if (av[i] == '-')
	    neg = neg * (-1);
	  if (av[i] >= '0' && av[i] <= '9')
	    nbr = (av[i] - 48) + (10 * nbr);
	  i++;
	}
      if (av[i] < '0' || av[i] > '9')
	{
	  nbr = nbr * neg;
	  return (nbr);
	}
      i++;
    }
  return (nbr);
}
