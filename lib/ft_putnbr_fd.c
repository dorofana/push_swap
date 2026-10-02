#include "push_swap.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	char	c;

	if (nbr == (-2147483647 - 1))
		return (ft_putstr_fd("-2147483648", fd));
	else if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		 ft_putnbr_fd((nbr / 10), fd);
	c = (nbr % 10) + '0';
	if (write(fd, &c, 1) == -1)
		return ;
}
