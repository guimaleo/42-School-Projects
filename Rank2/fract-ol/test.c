#include <stdio.h>
#include <stdlib.h>

int	ft_power(int x, int y){
	//x^y = x * x * x* x (y);
	int res = 0;

	if (y == 0)
		return 1;
	res = x;
	printf("%i\t%i\n", res, y);
	while (y > 1){
		res *= x;
		y--;
	}
	return res;
}

int main(int ac, char **av){
	if (ac < 3)
		return 1;
	int x = atoi(av[1]);
	int y = atoi(av[2]);
	int res = power(x, y);
	printf("%i\n", res);
}
