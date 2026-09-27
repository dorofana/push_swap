#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
