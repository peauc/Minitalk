/*
** main.c for main in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 18:53:38 2016 Clement Peau
** Last update Thu Feb  4 18:28:35 2016 Clement Peau
*/

#include "minitalk.h"

void	get_pid(int *pid, int value, int *got_pid)
{
  if (*got_pid == 0)
    {
      if (value == 0)
	{
	  *got_pid = 1;
	  return ;
	}
      *pid = *pid * 10;
      *pid += value - 48;
    }
  else if (value != 0)
    my_puttable(value);
  if (value == 0 && *got_pid == 1)
    {
      *got_pid = 0;
      *pid = 0;
    }
}

void	add_number(int nb)
{
  static int		loop = 7;
  static int		value = 0;
  static int		pid = 0;
  static int		got_pid = 0;

  value += (nb << loop--);
  if (got_pid == 1)
      kill(pid, SIGUSR1);
  if (loop < 0)
    {
      loop = 7;
      get_pid(&pid, value, &got_pid);
      value = 0;
    }
}

void	one()
{
  add_number(1);
}

void	zero()
{
  add_number(0);
}

int	main()
{
  my_putnbr(getpid());
  write(1, "\n", 1);
  signal(SIGUSR1, zero);
  signal(SIGUSR2, one);
  while (42);
}
