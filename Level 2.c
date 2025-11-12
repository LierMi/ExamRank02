//alpha_mirror
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		while (*s)
		{
			char	c = *s;

			if (c >= 'a' && c <= 'z')
				c = 'a' + ('z' - c);
			else if (c >= 'A' && c <= 'Z')
				c = 'A' + ('Z' - c);
			write(1, &c, 1);
			s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//camel_to_snake
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		while (*s)
		{
			char	c = *s;
			if (c >= 'A' && c <= 'Z')
			{
				char	u = '_';
				write (1, &u, 1);
				c += 32;
			}
			write(1, &c, 1);
			s++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

//do_op
#include <stdio.h> //printf
#include <stdlib.h> //atoi
#include <unistd.h> //write

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		int		a = atoi(av[1]);
		int		c = atoi(av[3]);
		char	b = av[2][0];
		int		res = 0;

		if (b == '+')
			res = a + c;
		else if (b == '-')
			res = a - c;
		else if (b == '*')
			res = a * c;
		else if (b == '/')
		{
			if (c == 0)
				res = 0;
			else
				res = a / c;
		}
		else if (b == '%')
		{
			if (c == 0)
				res = 0;
			else
				res = a % c;
		}
		printf("%d\n", res);
	}
	else
		write(1, "\n", 1);
	return (0);
}

//ft_atoi
int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == " " || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign == -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(sign * result));
}

//*ft_strcmp
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
/*int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 = *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}*/

//ft_strcspn
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(s[i++])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j++])
				return (i);
		}
	}
	return (i);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i = 0;

	while (s[i])
	{
		const char	*r = reject;
		while (*r && *r != s[i])
			r++;
		if (*r)
			return (i);
		i++;
	}
	return (i);
}

//ft_strspn
size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i = 0;

	while (s[i])
	{
		size_t	j = 0;
		while (accept[j] && s[i] != accept[j])
			j++;
		if (!accept[j])
			return (i);
		i++;
	}
	return (i);
}

//*ft_strdup
static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(src);
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}

//ft_strpbrk string pointer break
#include <stddef.h>
char	ft_strpbrk(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (*s2 == '\0')
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}

//ft_strrev
char	*ft_strrev(char *str)
{
	int	i = 0;
	int	j = 0;

	while (str[j])
		j++;
	j--;
	while (i < j)//左右对撞交换
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j++;
		j--;
	}
	return (str);
}

char	*ft_strrev(char *str)
{
	char *left = str;
	char *right = str;
	char tmp;

	while (*right)
		right++;
	right--;

	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
	return (str);
}

//inter
//判断字符 c 是否在 s1 的 更早位置（[0 .. i-1]）出现过。
int	seen_in_s1_before(const char *s1, int i, char c)
{
	int	j = 0;

	while (j < i)
	{
		if (s1[j] == c)
			return (1);
		j++;
	}
	return (0);
}

//判断字符 c 是否存在于第二个字符串 s2 中
int	seen_in_s2(const char *s2, char c)
{
	int	k = 0;

	while (s2[k])
	{
		if (s2[k] == c)
			return (1);
		k++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		const char *s1 = av[1];
		const char *s2 = av[2];
		int i = 0;

		while (s1[i])
		{
			char c = s1[i];
			if (!seen_in_s1_before(s1, i, c))
			{
				if (seen_in_s2(s2, c))
					write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int i = 0, j;
	int lookup[256] = {0};

	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j] && !lookup[(int)av[2][j]])
				{
					lookup[(int)av[2][j]] = 1;
					ft_putchar(av[2][j]);
				}
				j++;
			}
			i++;
		}
		ft_putchar('\n');
	}
}

//last_word
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		int		i = 0;
		int		end;

		while (s[i])
			i++;
		while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t'))
			i--;
		end = i;
		while (i > 0 && (s[i - 1] != ' ' || s[i - 1] != '\t'))
			i--;
		while (i < end)
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (0);
	}
}

//ft_is_power_2
int	is_power_of_2(unsigned int n)
{
	return (n != 0 && (n & (n - 1)) == 0);
}

int	is_power_of_2(unsigned int n)
{
	unsigned int	test = 1;

	while (test && test <= n)
	{
		if (test == n)
			return (1);
		test = test * 2;
	}
	return (0);
}

//max
int	max(int *tab, unsigned int len)
{
	if (len == 0 || tab == 0)
		return (0);
	int				max = tab[0];
	unsigned int	i = 1;

	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

//print_bits
void	print_bits(unsigned char octet)
{
	int	i = 7; // 从最高位(第7位)开始到最低位(第0位)

	while (i >= 0)
	{
		char	bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}
// (octet >> i)  : 把第 i 位移到最低位位置
// & 1           : 只保留最低位(得到 0 或 1)
// + '0'         : 把 0/1 转成字符 '0'/'1'

//reverse_bits
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res = 0;//结果累加器
	unsigned char	i = 8;

	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
	}
	return (res);
}
// res 向左移 1 位，为下一位留出最低位
// 例如 res: 0000 0101 -> 0000 1010
// (octet & 1) 取出 octet 的最低位（LSB），只会是 0 或 1


//wdmatch    word match
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		char	*s1 = av[1];
		char	*s2 = av[2];
		int		i = 0;
		int		j = 0;

		while (s1[i] && s2[j])
		{
			if (s2[j] == s1[i])
				i++;
			j++;
		}
		if (s1[i] == '\0')
		{
			int	k = 0;
			while (s1[k])
			{
				write(1, &s1[k], 1);
				k++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

int	main(int ac, char ** av)
{
	if (ac == 3)
	{
		const char	*s1 = av[1];
		const char	*s2 = av[2];
		int			len = 0, i = 0;

		while (s1[len])
			len++;
		while (i < len && s2)
		{ //这正是“子序列”匹配的经典两指针写法：s1 只在匹配时前进一步，s2 每步都前进
			if (s1[i] == *s2++)
				i++;
		}
			if (i == len)
				write(1, s1, len);
	}
	write(1, "\n", 1);
	return (0);
}

//swap_bits
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4 | octet << 4));
}
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet & 0x0F) << 4) | ((octet & 0xF0) >> 4);
}

//union
int	main(int ac, char**av)
{
	if (ac == 3)
	{
		int	seen[256] = {0};//创建一个长度 256 的整型数组，全初始化为 0
		int	i = 0;

		while (av[1][i])
		{//一定要用 unsigned char 来从 0..255 定位，避免负下标
			unsigned char	c = (unsigned char)av[1][i];
			if (!seen[c])
			{
				write(1, &av[1][i], 1);
				seen[c] = 1;
				//把该字符标记为“已经输出过”，后续再遇到就不再输出（实现去重）
			}
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			unsigned char	c = (unsigned char)av[2][i];
			if(!seen[c])
			{
				write(1, &av[2][i], 1);
				seen[c] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

//snake_to_camel
int	toUpper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int ft_putchar(char c)
{
	return write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == '_')
				ft_putchar(toUpper(av[1][++i]));
			else
				ft_putchar(av[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}

int	main(int ac, char **av)
{
	char	*s;
	char	c;
	int		i;
	int		cap;

	if (ac == 2)
	{
		s = av[1];
		i = 0;
		cap = 0;
		while (s[i])
		{
			if (s[i] == '_')
				cap = 1;
			else
			{
				c = s[i];
				if ((cap == 1) && c >= 'a' && c <= 'z')
					c -= 32;
				write(1, &c, 1);
				cap = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	res;
	unsigned int	bit_value;

	i = 0;
	res = 0;
	while (i < 8)
	{
		j = 8 - i - 1;
		bit_value = (octet & (1 << j)) != 0;
		if (bit_value)
			res = res | (1 << i);
		i++;
	}
	return (res);
}


unsigned char swap_bits(unsigned char octet)
{
	unsigned char	res;
	unsigned int	i;
	i = 0;
	res = 0;
	while (i < 4)
	{
		if ((octet & (1 << i)) != 0)
			res = res | (1 << (i + 4));
		i++;
	}
	while (i < 8)
	{
		if ((octet & (1 << i)) != 0)
			res = res | (1 << (i - 4));
		i++;
	}
    return res;
}

void test()
{
	unsigned char	res = 0;
	res = res | 0; // DOES NOTHING
	res = res & (~0); // DOES NOTHING
 	res = res | (1 << 2);
	res = res & (~(1 << 4));
}