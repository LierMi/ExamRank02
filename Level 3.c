//add_prime_sum
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar((char)('0' + n));
}

int	ft_isdigit(char c)
{
	return ( c >= '0' && c <= '9');
}
int	ft_atoi_positive(const char *s)
{
	int	i;
	int	val;

	if (!s || !s[0])
		return (-1);
	i = 0;
	val = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (-1);
		val = val * 10 + (s[i] - '0');
		i++;
	}
	if (val <= 0)
		return (-1);
	return (val);
}

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	sum_primes_upto(int n)
{
	int	i;
	int	sum;

	if (n < 2)
		return (0);
	i = 2;
	sum = 0;
	while (i <= n)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(int ac, char **av)
{
	int	n;
	int	sum;

	if (ac != 2)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	n = ft_aoi_positive(av[1]);
	if (n == -1)
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	sum = sum_primes_upto(n);
	ft_putnbr(sum);
	ft_putchar('\n');
	return (0);
}

//epur_str épurer string 把字符串净化
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_space(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}
/*int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}*/

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i = 0;
		int	space = 0;

		while (av[1][i] && is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			if (is_space(av[1][i]))
				space = 1;
			if (!is_space(av[1][i]))
			{
				if (space)// if (space == 1)
					ft_putchar(' ');
				space = 0;
				ft_putchar(av[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}

//expand_str
//void ft_putchar(char c);

//int is_space(char c);

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0, space = 0;

		while (av[1][i] && is_space(av[1][i]))
			i++;
		while (av[1][i])
		{
			if (is_space(av[1][i]))
				space = 1;
			if (!is_space(av[1][i])) //else
			{
				if (space)
					write(1, "   ", 3);
				space = 0;
				ft_putchar(av[1][i]);
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}

//ft_atoi_base
//把一个字符转成数值（0~15）
int	char_to_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	if (c >= 'A' && c <= 'F')
		return (10 + (c - 'A'));
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int sign;
	int	val;
	int result;

	if (!str || str_base < 2 || str_base > 16)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		val = char_to_val(str[i]);
		if (val < 0 || val >= str_base)
			break ;
		result = result * str_base + val;
		i++;
	}
	return (sign * result);
}

//ft_list_size
/*#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i = 0;

	while (begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

int	ft_list_size(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}*/

//ft_range
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	len;
	int	step;
	int	i;
	int	*arr;

	if (start <= end)
		len = end - start + 1;//升序
	else
		len = start - end + 1;//降序
	step = (start <= end) ? 1 : -1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = start + i * step;
		i++;
	}
	return (arr);
}

//ft_rrange
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	step;
	int	i;
	int	*arr;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	step = (end <= start) ? 1: -1;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = end + i * step;
		i++;
	}
	return (arr);
}

//hidenp
int	main(int ac, char **av)
{
	int i = 0, j = 0;

	if (ac == 3)
	{
		while (av[2][j] && av[1][i])
		{
			if (av[2][j] == av[1][i])
				i++;
			j++;
		}
		if (av[1][i] == 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}

//lcm
unsigned int	ft_gcd(unsigned int a, unsigned int b)
{
	/* 欧几里得算法：反复做 a%b，直到余数为 0 */
	while (b != 0)
	{
		unsigned int r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int g;

	if (a == 0 || b == 0)
		return (0);
	g = ft_gcd(a, b);
	return (a / g) * b;
}
//lcm 朴素暴力
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	i;// i = (a > b) ? a : b

	if (a == 0 || b == 0)
		return (0);
	i = 1;
	while (1)
	{
		if (1 % a == 0 && i % b == 0)// i 同时能被 a 和 b 整除
			return (i);
		i++;
	}
}

//paramsum
#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	(void)av;
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return (0);
}

//pgcd
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	num1 = atoi(av[1]);
		int	num2 = atoi(av[2]);
//减法版欧几里得算法
		if (num1 > 0 && num2 > 0)
		{
			while (num1 != num2)
			{
				if (num1 > num2)
					num1 = num1 - num2;
				else
					num2 = num2 - num1;
			}
			printf("%d", num1);
		}
	}
	printf("\n");
}

unsigned int	ft_gcd(unsigned int a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int r = a % b;
		a = b;
		b = r;
	}
	return (a);
}

unsigned int	ft_gcd(unsigned int a, unsigned int b)
{
	unsigned int lower;
	unsigned int cur;

	if(a<b)
	{
		lower = a;
	}
	else
	{
		lower = b;
	}
	cur = lower;
	while (cur > 1)
	{
		if (a % lower == 0 && b % lower == 0)
			return (lower);
		cur = cur - lower;
	}
	return (lower);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *str1 = av[1];
	char *str2 = av[2];

	int i = 0;
	int j = 0;
	while(str1[i])
	{
		while(str2[j] && str2[j] != str1[i])//)
		{
			j++;
		}
		i++;
		if(!str2[j])
		{
			write(1, "0", 1);
			write(1, "\n", 1);
			return (0);
		}
		j++;
	}
	write(1, "1", 1);
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("\n");
		return (0);
	}
	int	a = atoi(av[1]);
	int b = atoi(av[2]);
	if (a <= 0 || b <= 0)
	{
		printf("\n");
		return (0);
	}
	printf("%u\n", ft_gcd((unsigned int)a, (unsigned int)b))
	return (0);
}
//print_hex
unsigned int	ft_atoi(char *str)
{
	unsigned int	res = 0, i = 0;

	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (unsigned int)(str[i] - '0');
		i++;
	}
	return (res);
}

void	put_hex0(unsigned int n)
{
	char	*digits = "0123456789abcdef";
	char	c;

	if (n >= 16)
		put_hex(n / 16);
	c = digits[n % 16];
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		put_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}

//rstr_capitalizer
#include <unistd.h>

int	ft_isletter(char c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	r_capitalizer(char *s)
{
	int		i = 0;
	char	c;
	char	nxt;

	while (s[i])
	{
		c = s[i];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		nxt = s[i + 1];
		if ((c >= 'a' && c <= 'z') && !ft_isletter(nxt))
			c -= 32;
		ft_putchar(c);
		i++;
	}
}

int	main(int ac, char **av)
{
	int i = 1;

	if (ac <= 1)
	{
		ft_putchar('\n');
		return (0);
	}
	while (i < ac)
	{
		r_capitalizer(av[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

//str_capitalizer
int	ft_isletter(char c)
{
	return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_capitalizer(char *s)
{
	int		i = 0;
	char	c;
	char	prv;

	while (s[i])
	{
		c = s[i];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		prv = (i > 0) ? s[i - 1] : ' ';
		/*if (i > 0)
			prv = s[i - 1];
		else
			prv = ' ';*/
		if (ft_isletter(c) && (i == 0 || prv == ' ' || prv == '\t'))
			c -= 32;
		ft_putchar(c);
		i++;
	}
}

int	main(int ac, char **av)
{
	int i = 1; //av[1]

	if (ac <= 1)
	{
		ft_putchar('\n');
		return (0);
	}
	while (i < ac)
	{
		str_capitalizer(av[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

//tab_mult
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int n)
{
	/*if (n == -2147483648)
	{
		write(1, "-2147482648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}*/
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((char)((n % 10) + '0'));
}

int	ft_atoi(char *s)
{
	int	i = 0;
	int	res = 0;

	while (s[i] <= 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			return (0);
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	n = ft_atoi(av[1]);
		int	i = 1;

		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(n);
			write(1, " = ", 3);
			ft_putnbr(i * n);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
