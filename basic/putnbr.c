/*
** putnbr.c for putnbr in /home/peau_c/rendu/PSU/PSU_2015_minitalk/basic
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 20:38:50 2016 Clement Peau
** Last update Mon Feb  1 21:06:52 2016 Clement Peau
*/

#include "minitalk.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnbr(int i)
{
  if (i > 0)
    {
      my_putnbr(i / 10);
      my_putchar(i % 10 + 48);
    }
}
