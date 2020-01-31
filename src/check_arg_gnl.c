/*
** check_arg_get_next.c for  in /home/M-P.anselin/delivery/CPE/CPE_2016_matchstick
** 
** Made by Anselin Mackendy-pierre
** Login   <M-P.anselin@epitech.net>
** 
** Started on  Mon Feb 20 16:18:08 2017 Anselin Mackendy-pierre
** Last update Sun Feb 26 22:25:45 2017 Anselin Mackendy-pierre
*/

#include	"matchstick.h"

int	check_line_nbr_stick(int var, int line, char **map, int max)
{
  int	x;
  int	nbr;

  x = 0;
  nbr = 0;
  while (map[line][x] != '\0')
    {
      if (map[line][x] == '|')
	nbr++;
      x++;
    }
  if (var > max)
    {
      my_printf("Error: you cannot remove more than");
      my_printf(" %d matches per turn\n", max);
      return (-1);
    }
  if (var > nbr)
    {
      my_printf("Error: not enough matches on this line\n");
      return (-1);
    }
  return (var);
}

int	check_var(int var, int line_stick, int nbr)
{
  int	x;

  x = 0;
  if (var <= 0)
    {
      if (nbr == 1)
	my_printf("Error: this line is out of range\n");
      else
	my_printf("Error: you have to remove at least one match\n");
      return (-1);
    }
  if (nbr == 1 && var > line_stick)
    {
      my_printf("Error: this line is out of range\n");
      return (-1);
    }
  return (var);
}

int	check_arg(char *stock, int line_stick, int nbr)
{
  int	x;
  int	len;
  int	var;

  x = 0;
  len = 0;
  while (stock[len] != '\0')
    len++;
  while (stock[x] >= 48 && stock[x] <= 57)
    x++;
  if (x != len)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  var = my_getnbr(stock);
  if ((var = check_var(var, line_stick, nbr)) == -1)
    return (-1);
  return (var);
}

int	arg_line(int line_stick)
{
  char	*stock;
  int	var;

  if ((stock = get_next_line(0)) == NULL)
    return (-2);
  while ((var = check_arg(stock, line_stick, 1)) == -1)
    {
      my_printf("Line: ");
      if ((stock = get_next_line(0)) == NULL)
	return (-2);
    }
  return (var);
}

int	arg_matches(int line, char **map, int line_stick, int max)
{
  char	*stock;
  int	var;

  if ((stock = get_next_line(0)) == NULL)
    return (-2);
  var = check_arg(stock, line_stick, 2);
  var = check_line_nbr_stick(var, line, map, max);
  while (var ==  -1)
    {
      my_printf("Line: ");
      if ((line = arg_line(line_stick)) == -2)
	return (-2);
      my_printf("Matches: ");
      if ((stock = get_next_line(0)) == NULL)
	return (-2);
      var = check_arg(stock, line_stick, 2);
      var = check_line_nbr_stick(var, line, map, max);
    }
  return (var);
}
