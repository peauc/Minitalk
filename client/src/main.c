/*
** main.c for main in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 18:54:04 2016 Clement Peau
** Last update Thu Feb 25 18:58:13 2016 Clement Peau
*/

#include "minitalk.h"

void	parse_it(char *str, pid_t pid, int is_sent)
{
  int		i;
  int		decal;

  i = 0;
  while (str[i] != 0)
    {
      decal = 7;
      while (decal >= 0)
	{
	  ((str[i] >> decal--) & 1 ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
	  usleep(1000);
	}
      usleep(1);
      i++;
    }
  send_signals(0, pid, is_sent);
}

char		*putpid(char *pid, int nbr)
{
  static int	count = 0;

  if (nbr > 0)
    {
      putpid(pid, nbr / 10);
      pid[count++] = nbr % 10 + 48;
      pid[count] = 0;
      return (pid);
    }
  return (pid);
}

char	*get_the_pid()
{
  pid_t	pid;
  char	*str;

  pid = getpid();
  if ((str = malloc(10)) == NULL)
    return (NULL);
  str = putpid(str, pid);
  return (str);
}

void		received()
{
}

int		main(int ac, char **av, char **ae)
{
  char		*str;

  ac = ac;
  g_globale = 0;
  if (ae == NULL)
    return (1);
  if (av[1] == NULL || av[2] == NULL)
    return (1);
  signal(SIGUSR1, received);
  if (getnbr(av[1]) <= 0)
    {
      write(2, "Wrong PID\n", 10);
      return (80085);
    }

  if ((str = get_the_pid()) == NULL)
    return (1);
  parse_it(str, getnbr(av[1]), 0);
  parse_it(av[2], getnbr (av[1]), 1);
  free(str);
  return (1);
}
