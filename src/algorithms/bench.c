#include "push_swap.h"

static void	disorder_print(t_grid *push_swap)
{
	int	total;
	int	whole;
	int	dec;
	
	total = (int)(push_swap->disorder * 10000);
	whole = total / 100;
	dec = total_eval % 100;
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (dec < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(dec, 2);
	ft_putstr_fd("%\n", 2);
}

static void	mode_print(t_grid *push_swap)
{
	char	*str;
	
	if (push_swap->mode == MODE_SIMPLE)
		str = "Simple / O(n^2)";
	if (push_swap->mode == MODE_MEDIUM)
		str = "Medium / O(n√n)";
	if (push_swap->mode == MODE_COMPLEX)
		str = "Complex / O(n log n)";
	if (push_swap->disorder < 0.2)
		str = "Simple / O(n^2)";
	if (pusw_swap->disorder >= 0.2 && push_swap->disorder < 0.5)
		str = "Medium / O(n√n)";
	if (push_swap->disorder >= 0.5)
		str = "Complex / O(n log n)";
	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putendl_fd(str, 2);
}

static void	operations_1(t_grid *push_swap)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	operations_2(t_grid *push_swap)
{
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(push_swap->ops.count.rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	bench_print(t_grid *push_swap)
{
	if(!push_swap->bench_mode)
		return ;
	disorder_print(push_swap);
	mode_print(push_swap);
	total_print(push_swap);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(push_swap->ops_count.total_ops, 2);
	ft_putchar_fd('\n', 2);
	operations_1(push_swap);
	operations_2(push_swap);
}
