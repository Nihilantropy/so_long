#include <stdio.h>

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			i += 2;
		if ((str[i] >= 'A' && str[i] <= 'J') ||
		(str[i] >= 'a' && str[i] <= 'j'))
			str[i] = str[i] + 16;
		else if ((str[i] >= 'K' && str[i] <= 'Z') ||
		(str[i] >= 'k' && str[i] <= 'z'))
			str[i] = str[i] - 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		printf("%s", ft_rot42(argv[i]));
}
