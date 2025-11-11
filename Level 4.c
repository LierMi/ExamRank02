//fprime
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i;
	int	num;
//i：当前尝试的因子，从 2 开始（最小素数）。
//num：将字符串参数转成的整数，等会儿存放到这里。
	i = 2;
	if (ac == 2)
	{
		num = atoi(av[1]);
		if (num == 1)
			printf("1");
		while (i <= num)//当当前候选因子 i 不超过 当前剩余的 num 时，继续尝试
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num != i)
					printf("*");
				num = num / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}

//ft_split
int	count_words(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			i++;
	}
	return (count);
}

char	**ft_split(char *str)
{

}

//ft_itoa
#include <stdlib.h>

int	ft_count_len(int nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)//0 需要 1 个字符（"0"）。//负数需要多一个 '-' 号位置。
		i++;
	while (nbr != 0)//每除以 10 相当于“去掉一位”，数一数要多少次变成 0。
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int		i;
	int		len;
	long	num;
	char	*str;

	num = nbr;
	len = ft_count_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;//i 指向最后一个可写位置（末尾 '\0' 的前一格）
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 9)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	str[i] = num + '0';
	return (str);
}

//flood_fill
void	fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] != target || tab[row][col] == 'F')
		return ;
	tab[row][col] = 'F';
	fill(tab, size, target, row - 1, col);
	fill(tab, size, target, row + 1, col);
	fill(tab, size, target, row, col - 1);
	fill(tab, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	//if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y)
	//	return ;
	char	target = tab[begin.y][begin.x];
	fill(tab, size, target, begin.y, begin.x);
}
