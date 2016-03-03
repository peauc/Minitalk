/*
** main.c for main in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 18:54:04 2016 Clement Peau
** Last update Sun Feb 21 20:30:43 2016 Clement Peau
*/

#include "minitalk.h"

void	send_signals(char c, pid_t pid, int is_sent)
{
  int	decal;

  is_sent = is_sent;
  decal = 7;
  while (decal >= 0)
    {
      ((c >> decal--) & 1 ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(10000);
    }
  usleep(1);
}
