/*
** main.c for main in /home/lavala_c/PSystemUnix/PSU_2015_bstetris
** 
** Made by Lavalard Charles
** Login   <lavala_c@epitech.net>
** 
** Started on  Thu Feb 25 14:24:15 2016 Lavalard Charles
** Last update Thu Mar 17 14:02:05 2016 Lavalard Charles
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"get_next_line.h"

int		get_next_number(char *str, int *i)
{
  while (str[(*i)] != ' ' && str[(*i)])
    (*i)++;
  if (str[(*i)] == '\0')
    return (-1);
  return (0);
}

void  		get_info(char *str, int *len, int *hi, int *color)
{
  char		*info;
  int		i;
  int		diff;

  i = 0;
  get_next_number(str, &i);
  info = my_strcpy(str, i, (i-1));
  i++;
  diff = i;
  (*len) = my_getnbr(info);
  get_next_number(str, &i);
  diff = i - diff;
  info = my_strcpy(str, diff, (i-1));
  i++;
  diff = i;
  (*hi) = my_getnbr(info);
  get_next_number(str, &i);
  diff = i - diff;
  info = my_strcpy(str, diff, (i-1));
  i++;
  diff = i;
  (*color) = my_getnbr(info);
}

void		get_name(char *str)
{
  int		tetre;
  int		i;

  i = 0;
  tetre = my_strlen(str) - 10;
  if (tetre <= 0)
    {
      my_putstr("Error");
      exit(0);
    }
  my_putstr("Tetriminos : Name ");
  while (i != tetre)
    {
      my_putchar(str[i]);
      i++;
    }
    my_putstr(" : ");
}

int		check_and_print(int len, int hi, int fd)
{
  int		i;
  int		j;
  int		turn;
  char		*line;

  i = 0;
  j = 0;
  turn = 0;
  while (i != hi)
    {
      j = 0;
      if ((line = get_next_line(fd)) == NULL)
	return (1);
      while (line[j])
	j++;
      if (j == len)
	turn++;
      my_putstr(line);
      my_putchar('\n');
      i++;
    }
  return (0);
}
void		print_info(int len, int hi, int col)
{
  my_putstr("Size ");
  my_putnbr(len);
  my_putchar('*');
  my_putnbr(hi);
  my_putstr(" : Color ");
  my_putnbr(col);
  my_putstr(" :");
  my_putchar('\n');
}
int		main(int ac, char **av)
{
  int		fd;
  char		*first_line;
  int		len;
  int		hi;
  int		color;

  len = 0;
  hi = 0;
  color = 0;
  if (ac != 2)
    return (1);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr("Error\n");
      return (1);
    }
  get_name(av[1]);
  if ((first_line = get_next_line(fd)) == NULL)
    {
      my_putstr("Empty file\n");
      return (1);
    }
  get_info(first_line, &len, &hi, &color);
  if (hi <= 0 || len <= 0)
    {
      my_putstr("Error\n");
      exit(0);
    }
  print_info(len, hi, color);
  check_and_print(len, hi, fd);
}
