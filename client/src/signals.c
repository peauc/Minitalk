/*
** main.c for main in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 18:54:04 2016 Clement Peau
** Last update Thu Feb  4 18:18:29 2016 Clement Peau
*/

#include "minitalk.h"

void	ping_pong(t_union oignon, pid_t pid)
{
  ((oignon.field.eight) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.seven) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.six) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.five) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.four) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.three) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.two) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  ((oignon.field.one) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
  while (g_globale != 1);
  g_globale = 0;
  usleep(1);
}

void	send_signals(t_union oignon, pid_t pid, int is_sent)
{
  if (is_sent == 1)
    ping_pong(oignon, pid);
  else
    {
      ((oignon.field.eight) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.seven) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.six) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.five) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.four) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.three) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.two) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
      ((oignon.field.one) ? kill(pid, SIGUSR2) : kill(pid, SIGUSR1));
      usleep(1000);
    }
}
