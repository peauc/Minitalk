/*
** strlen.c for strle in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 21:09:37 2016 Clement Peau
** Last update Mon Feb  1 21:12:08 2016 Clement Peau
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i++] != 0);
  return (i);
}
