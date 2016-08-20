/*
** my_getnbr.c for make in /home/lavala_c/CProgElem/CPE_2015_Allum1
** 
** Made by Lavalard Charles
** Login   <lavala_c@epitech.net>
** 
** Started on  Mon Feb 15 11:00:57 2016 Lavalard Charles
** Last update Thu Feb 25 16:44:36 2016 Lavalard Charles
*/

#include	"get_next_line.h"

int		is_neg(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	count++;
      i++;
    }
  if (count % 2 != 0)
    return (1);
  else
    return (0);
}

int		is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    {
      if (!str[i])
        return (0);
      i++;
    }
  while (is_num(str[i]) == 1)
    {
      nb = ((nb * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nb = -nb;
  return (nb);
}
