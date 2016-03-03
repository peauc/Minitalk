/*
** my_puttable.c for puttable in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 21:44:45 2016 Clement Peau
** Last update Fri Feb 19 17:52:19 2016 Clement Peau
*/

#include "minitalk.h"

void	my_puttable(unsigned char c)
{
  write(1, &c, 1);
}
