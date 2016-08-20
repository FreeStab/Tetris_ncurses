/*
** puts.c for puts in /home/lavala_c/PSystemUnix/PSU_2015_bstetris
** 
** Made by Lavalard Charles
** Login   <lavala_c@epitech.net>
** 
** Started on  Thu Feb 25 15:45:49 2016 Lavalard Charles
** Last update Thu Feb 25 16:54:38 2016 Lavalard Charles
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"

void            my_putchar(char c)
{
  write(1, &c, 1);
}

int             my_strlen(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void            my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}

char            *my_strcpy(char *str, int len, int i)
{
   char          *new;
   int           j;

  j = 0;
   if ((new = malloc(sizeof(char) * len + 1)) == NULL)
   return (NULL);
 while (j != len)
  {
      new[j] = str[i];
       i++;
     j++;
    }
  new[i] = '\0';
   return (new);
 }

void            my_putnbr(int nb)
{
  int           i;

  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  i = nb % 10;
  if (nb / 10 != 0)
    my_putnbr(nb / 10);
  my_putchar((char)i + 48);
}
