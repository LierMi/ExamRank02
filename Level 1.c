// first_word
#include <unistd.h>

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		unsigned int	i;

		i = 0;
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while((av[1][i] != 32 && av[1][i] != 9) && av[1][i])
			write(1, &av[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char *s = av[1];

		while (*s == ' ' || *s == '\t')
			s++;
		while (*s && *s != ' ' && *s != '\t')
			write(1, s++, 1);
	}
	write(1, "\n", 1);
	return (0);
}

//fizzbuzz
#include <unistd.h>

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1,&"0123456789"[i % 10], 1);
	//char	c = '0' + (i % 10); write(1, &c, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		i++;
		write(1, "\n", 1);
	}
}

//ft_putstr
void	ft_putstr(char *str)
{
	unsigned int	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	/*while (*str)
	{
		write(1, str, 1);
		str++;
	}*/
}

//ft_strcpy
char	*ft_strcpy(char *s1, char *s2)
{
	unsigned int	i = 0;

	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);

	/*char	*dst = s1;

	while (*s2)
		*dst++ = *s2++;
	*dst = '\0';
	return (s1);*/
}

//ft_strlen
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	retutn (i);
}

//ft_swap
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

//repeat_alpha
#include <unistd.h>

static void	putnchar(char c, int n)
{
	while (n-- > 0)
		write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];

		while (*s)
		{
			char	c = *s;
			int		rep = 1;

			if (c >= 'a' && c <= 'z')
				rep = c - 'a' + 1;
			else if (c >= 'A' && c <= 'Z')
				rep = c - 'A' + 1;
			putnchar(c, rep);
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//rev_print
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	i;

		i = 0;
		while (av[1][i])
			i++;
		while (i--)//while (i > 0) i--;
			write(1, &av[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}

//rot_13
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];

		while (*s)
		{
			char	c = *s;

			if (c >= 'a' && c <= 'm')
				c += 13;
			else if (c >= 'A' && c <= 'M')
				c += 13;
			else if (c >= 'n' && c <= 'z')
				c -= 13;
			else if (c >= 'N' && c <= 'Z')
				c -= 13;
			write(1, &c, 1);
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//rotone
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];

		while (*s)
		{
			char	c = *s;

			if (c >= 'a' && c <= 'y')
				c += 1;
			else if (c == 'z')
				c = 'a';
			else if (c >= 'A' && c <= 'Y')
				c += 1;
			else if (c == 'Z')
				c = 'A';
			write(1, &c, 1);
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
//search_and_replace
int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int	i;

		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == av[2][0])
				av[1][i] = av[3][0];
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

ststic int	is_single_char(char *s)
{
	return (s && s[0] && s[1] == '\0');
	//return (s != NULL) && (s[0] != '\0') && (s[1] == '\0')
}
/*if (s == NULL)
	return (0);
if (s[0] == '\0')
	return (0);
if (s[1] != '\0')
	return (0);
return (1);*/

int	main(int ac, char **av)
{
	if (ac == 4 && is_single_char(av[2]) && is_single_char(av[3]))
	{
		char	*str = av[1];
		char	from = av[2][0];
		char	to = av[3][0];

		while (*str)
		{
			char	out = *str;

			if (out == from)
				out == to;
			write(1, &out, 1);
			str++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//ulstr
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];

		while (*s)
		{
			char	c = *s;

			if (c >= 'a' && c <= 'z')
				c -= 32;
			else if (c >= 'A' && c <= 'Z')
				c += 32;
			write(1, &c, 1);
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
