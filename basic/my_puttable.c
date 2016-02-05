/*
** my_puttable.c for puttable in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 21:44:45 2016 Clement Peau
** Last update Thu Feb  4 16:35:39 2016 Clement Peau
*/

void	my_puttable(unsigned char c)
{
  write(1, &c, 1);
}
