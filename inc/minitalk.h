/*
** minitalk.h for talk in /home/peau_c/rendu/PSU/PSU_2015_minitalk
**
** Made by Clement Peau
** Login   <peau_c@epitech.net>
**
** Started on  Mon Feb  1 20:45:33 2016 Clement Peau
** Last update Sat Feb 20 16:59:51 2016 Clement Peau
*/

#ifndef _MINITALK_H_
# define _MINITALK_H_

int	g_globale;

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

typedef struct	s_bitfield
{
  unsigned int	one : 1;
  unsigned int	two : 1;
  unsigned int	three : 1;
  unsigned int	four : 1;
  unsigned int	five : 1;
  unsigned int	six : 1;
  unsigned int	seven : 1;
  unsigned int	eight : 1;
}		t_bitfield;

typedef union	s_union
{
  t_bitfield	field;
  unsigned char	c;
}		t_union;

int getnbr(char *str);
void my_puttable(unsigned char);
void my_putnbr(int nb);
int my_strlen(char *);
void send_signals(char, pid_t, int);

# endif /* _MINITALK_H_ */
