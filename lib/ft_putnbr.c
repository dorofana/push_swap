#include "push_swap.h"

int	ft_putnbr(int nbr)
{
	int		count;
	int		tmp;
	char	c;

	count = 0;
	if (nbr == (-2147483647 - 1))
		return (ft_putstr("-2147483648"));
	else if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		tmp = ft_putnbr(nbr / 10);
		if (tmp == -1)
			return (-1);
		count += tmp;
	}
	c = (nbr % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (++count);
}
