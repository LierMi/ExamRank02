//alpha_mirror
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char	*s = av[1];
		while (*s)
		{
			char	c = *s;
//距离 'z' 多远，就从 'a' 往后走同样的距离
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
{//char *s 用来“走字符串”（地址/位置）。
//char c 用来“装当前字符并修改”（值/数据）
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
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
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
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}*/

//ft_strcspn
#include <stdio.h>
//string complement span
//计算字符串开头那一段不含指定字符集合（reject）的最长长度
//返回 s 开头那段“完全不包含 reject 任意字符”的最长前缀的长度。
//也可以理解为：第一个命中 reject 的位置索引；如果不命中，则返回 s 的长度
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);          // 返回第一次匹配到的下标
			j++;
		}
		i++;
	}
	return (i);                       // 没有任何命中，返回 strlen(s)
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
//strspn = string span，计算开头那一段只包含指定集合的长度
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

#include <stddef.h>

/*
** ft_strspn
** 返回字符串 s 从开头起、只由 accept 中字符组成的最长前缀长度。
** 若 s 的第 i 位不在 accept 中，则返回 i；若整串都在，则返回 strlen(s)。
*/
size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		size_t	j;

		j = 0;
		/* 在 accept 里找是否存在 s[i]；找到就提前 break，找不到就会停在 '\0' */
		while (accept[j])
		{
			if (accept[j] == s[i])
				break;
			j++;
		}
		/* 如果停在 '\0'，说明没找到匹配，s[i] 不属于 accept，返回当前长度 i */
		if (accept[j] == '\0')
			return (i);
		/* 否则说明 s[i] 合法，继续检查下一位 */
		i++;
	}
	/* 扫完整个 s 都合法，返回总长度 i */
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
	size_t	i = 0;
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
		while (i > 0 && (s[i - 1] != ' ' && s[i - 1] != '\t'))
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
