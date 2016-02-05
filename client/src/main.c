/*
** main.c for main in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 18:54:04 2016 Clement Peau
** Last update Thu Feb  4 18:20:45 2016 Clement Peau
*/

#include "minitalk.h"

void	parse_it(char *str, pid_t pid, int is_sent)
{
  int		i;
  t_union	oignon;

  i = 0;
  while (str[i] != 0)
    {
      oignon.c = str[i];
      send_signals(oignon, pid, is_sent);
      i++;
    }
  oignon.c = 0;
  send_signals(oignon, pid, is_sent);
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
  str = malloc(10);
  str = putpid(str, pid);
  return (str);
}

void		received()
{
  g_globale = 1;
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
  if (atoi(av[1]) <= 0)
    {
      write(2, "Wrong PID\n", 10);
      return (80085);
    }

  str = get_the_pid();
  parse_it(str, atoi(av[1]), 0);
  parse_it(av[2], atoi(av[1]), 1);
  free(str);
  return (1);
}
