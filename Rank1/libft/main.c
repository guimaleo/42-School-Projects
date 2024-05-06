/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lede-gui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:05:51 by lede-gui          #+#    #+#             */
/*   Updated: 2023/10/04 14:34:13 by lede-gui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>



int	ft_memory_tester(int x);

int	main()
{
	printf("\033[1;32m\nIs something tests\n\033[0m\n");
	if ((ft_isalpha(1) == isalpha(1)) && (ft_isalpha('a') == isalpha('a')))
		printf("ft_isalpha: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_isalpha: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if ((ft_isalnum(1) == isalnum(1)) && (ft_isalnum('B') == isalnum ('B')))
		printf("ft_isalnum: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_isalnum: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if ((ft_isascii(1) == isascii(1)) && (ft_isascii(126) == isascii(126)))
		printf("ft_isascii: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if ((ft_isdigit(48) == isdigit(48)) && (ft_isdigit('0') == isdigit('0')))
		printf("ft_isdigit: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_isdigit: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if ((ft_isprint(35) == isprint(35)) && (ft_isprint(112) == isprint(112)))
		printf("ft_isprint: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_isprint: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if ((ft_toupper('a') == toupper('a')) && (ft_toupper('z') == toupper('z')))
		printf("ft_toupper: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_toupper: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if ((ft_tolower('A') == tolower('A')) && (ft_tolower('Z') == tolower('Z')))
		printf("ft_tolower: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_tolower: \033[1;35mKO!!! Let's talk about it...\033[0m\n");

	printf("\033[1;32m\nFile Descriptor Tests\n\033[0m\n");

	int		fd[2];
	fd[0] = open("./fd_res.txt", O_CREAT | O_RDWR, 0666);
	if (fd[0] < 0){
		perror("open");
		return 1;
	}
	char	str[] = "Hello World!";
	ft_putstr_fd(str , fd[0]);
	close(fd[0]);

	fd[1] = open("./fd_res.txt", O_RDONLY);
	if (fd[1] < 0){
		perror("open");
		return 2;
	}
	char *res;
	res = malloc(14);
	if (!res)
		return (-1);
	res[13] = 0;
	read(fd[1], res, 13);
	close(fd[1]);
	if (!strcmp(res, str))
		printf("ft_putstr_fd: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_putstr_fd: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	free(res);


	fd[0] = open("./fd_res2.txt", O_WRONLY | O_CREAT, 0666);
	if (fd[0] < 0){
		perror("open");
		return (3);
	}
	ft_putendl_fd(str, fd[0]);
	close(fd[0]);
	char	res2[15];
	char	*compare;
	fd[1] = open("./fd_res2.txt", O_RDONLY);
	if (fd[1] < 0){
		perror("open");
		return (4);
	}
	read(fd[1], res2, 14);
	close(fd[1]);
	res2[14] = 0;
	compare = ft_strjoin(str, "\n");
	if (!strcmp(res2, compare))
		printf("ft_putendl_fd: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_putendl_fd: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	free(compare);
	int		test[5] = {42, 2147483648, 2147483641, -2147483642, -2147483648};
	int		i = -1;
	int		nbres[5];
	char		*temp;
	int		aux;
	bool	passed = true;
	int		size;
	while (i < 4)
	{
		++i;
		fd[0] = open("./fd_nbr.txt", O_CREAT | O_WRONLY, 0666);
		if (fd[0] < 0){
			perror("open");
			return (5);
		}
		ft_putnbr_fd(test[i], fd[0]);
		close(fd[0]);
		fd[1] = open("./fd_nbr.txt", O_RDONLY);
		if (fd[1] < 0){
			perror("open");
			return (6);
		}
		aux = test[i];
		size = 0;
		if (aux < 0)
			size = 1;
		while (aux)
		{
			aux /= 10;
			size++;
		}
		temp = (char *)malloc(size + 1);
		if (!temp)
			return (-1);
		temp[size] = 0;
		char	*to_pass;
		to_pass = ft_itoa(test[i]);
		read(fd[1], temp, size);
		close(fd[1]);
		//printf("to_pass-> %s\t\ttemp-> %s\n", to_pass, temp);
		if (strcmp(to_pass, temp))
			passed = false;
		ft_bzero(temp, size + 1);
		free(to_pass);
		free(temp);
	}
	if (passed)
		printf("ft_putnbr_fd: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_putnbr_fd: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	fd[0] = open("char.txt", O_CREAT | O_WRONLY, 0666);
	if (fd[0] < 0){
		perror("open");
		return (7);
	}
	ft_putchar_fd(11, fd[0]);
	close(fd[0]);
	fd[1] = open("char.txt", O_RDONLY);
	if (fd[1] < 0){
		perror("open");
		return (8);
	}
	temp = malloc(2);
	if(!temp)
		return (-1);
	read(fd[1], temp, 1);
	close(fd[1]);
	temp[1] = 0;
	if (temp[0] == 11)
		printf("ft_putchar_fd: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_putchar_fd: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	free(temp);
	printf("\033[1;32m\nStrings Tests\n\033[0m\n");
	int		x[10] = {INT_MIN, INT_MAX, 0, 42, -42, 1337, 8898291, 999999, 1111111, 9 };
	char	*x_res[10];

	x[0] = INT_MIN;
	x[1] = INT_MAX;

	passed = true;

	i = 0;
	while (i < 10)
	{
		x_res[i] = ft_itoa(x[i]);
		if (x[i] != atoi(x_res[i])){
			passed = false;
			break ;
		}
		i++;
	}
	if (passed)
		printf("ft_itoa: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_itoa: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	passed = true;
	i = 0;
	while (i < 10)
	{
		//printf("x[]%i\tx_res[]%i\n", x[i], ft_atoi(x_res[i]));
		if (x[i] == ft_atoi(x_res[i]))
		{
			if (ft_atoi(x_res[i]) != atoi(x_res[i]))
				passed = false;
		}
		i++;
	}
	if (passed)
		printf("ft_atoi: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_atoi: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	char	s[] = "             I have exactly 5 words!           ";
	if ((count_words(s, 32) == 5))
			printf("ft_count_words: \033[1;36mOK!\033[0m\n");
	else
			printf("ft_count_words: \033[1;35mKO!!! Let's talk about it...\033[0m\n");

	passed = true;
	char	to_split[] = "  Split usually has some problems in the count words logics!       ";
	i = 0;
	char	**split;
	split = ft_split(to_split, 32);
	while (split[i])
	{
		//printf("to_split[%i]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	if (i != count_words(to_split, 32))
		passed = false;
	free(split);

	if (passed)
		printf("ft_split: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_split: \033[1;35mKO!!! Let's talk about it...\033[0m\n");

	char	ns[] = "We don't like Francinette!";
	res = ft_strchr(ns, '!');
	if (res == strchr(ns, '!'))
		printf("ft_strchr: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_strchr: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	res = ft_strrchr(ns, '\'');
	//printf("%s\n", res);
	if (res == strrchr(ns, '\''))
		printf("ft_strrchr: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_strrchr: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
printf("\033[1;32m\nMemory Tests\n\033[0m\n");
	if ((ft_memory_tester(1)))
		printf("ft_memset: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_memset: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if (ft_memory_tester(0))
		printf("ft_bzero: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_bzero: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if (ft_memory_tester(2))
		printf("ft_memcmp: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_memcmp: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if (ft_memory_tester(3))
		printf("ft_memcpy: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_memcpy: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if (ft_memory_tester(4))
		printf("ft_memmove: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_memmove: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if (ft_memory_tester(5))
		printf("ft_memset: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_memset: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	printf("\033[1;32m\nLinked Lists Tests\n\033[0m\n");
/*
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
		if ((ft_isascii(1) == isascii(1)) && (ft_isacii(126) && isascii(126)))
			printf("ft_isascii: \033[1;36mOK!\033[0m\n");
		else
			printf("ft_isascii: \033[1;35mKO!!! Let's talk about it...\033[0m\n");*/
}

int	ft_memory_tester(int x)
{
	void	*p;
	void	*rip;
	bool	passed = true;


	p = malloc(10);
	if (!p)
		return (-1);
	rip = malloc(10);
	if (!rip)
		return (-1);
	if (x == 0)
	{
		if (!p || !rip)
			return (0);
		if (!memcmp(ft_memset(p, x, 10),memset(rip, x, 10), 10))
		{
			free(p);
			free(rip);
			return (1);
		}
		free(p);
		free(rip);
		return (0);
	}
	else if (x == 1)
	{
		if(!p || !rip)
			return(0);
		ft_bzero(p, 10);
		bzero(rip, 10);
		if (!memcmp(p, rip, 10))
		{
			free(p);
			free(rip);
			return (1);
		}
		free(p);
		free(rip);
		return (0);
	}
	else if (x == 2)
	{
		char	p[] = "Memory testing!\n";
		void	*mem;
		void	*memptr;

		mem = &p;
		memptr = (p +2);
		// printf("Custom: %i\n", ft_memcmp(mem, memptr, ft_strlen(p)));
		// printf("Original: %i\n", memcmp(mem, memptr, ft_strlen(p)));
		if (ft_memcmp(mem, memptr, ft_strlen(p)) == memcmp(mem, memptr, ft_strlen(p)))
			return (1);
		else
			return (0);
	}
	else if (x == 3)
	{
		char	p[] = "Memory testing!\n";
		void	*mem;
		void	*memptr;

		mem = &p;
		memptr = (p +2);
		//printf("Custom: %p\t%s\n", ft_memcpy(mem, memptr, ft_strlen(p)), p);
		//printf("Original: %p\t%s\n", memcpy(mem, memptr, ft_strlen(p)), p);

		if (ft_memcpy(memptr, mem, ft_strlen(p)) == memcpy(memptr, mem, ft_strlen(p)))
		{
			void	*dummy = NULL;
			if (!ft_memcpy(mem, dummy, ft_strlen(p)))
				return (1);
			else if (ft_memcpy(dummy, dummy, ft_strlen(p)))
				return (0);
		}
		else
			return (0);
	}
	else if (x == 4)
	{
		char	tab[] = "1 4 6 9";
		char	str[] = "mem is confusing";

		// printf("Address:\n%p\tContent: %s\n", &tab, tab);
		// printf("Address:\n%p\tContent: %s\n", &str, str);
		if (memcmp(ft_memmove(str, tab, 7), str, ft_strlen(str))
			&& !strcmp(ft_memmove(str, tab, 7), str)){
			printf("Address:\n%p\tContent: %s\n", &tab, tab);
			printf("Address:\n%p\tContent: %s\n", &str, str);
			return (0);
		}
		else
			return (1);
	}
	else
	{
		void	*ptr;
		void	*ptr2;

		ptr = malloc(10);
		ptr2 = malloc(10);
		if (!ptr || !ptr2)
			return (-1);
		ptr = memset(ptr, 65, 8);
		ptr2 = ft_memset(ptr2, 65, 8);
		// printf("%s|\n", (char *)ptr);
		// printf("%s|\n", (char *)ptr2);
		if (!strcmp(ptr, ptr2))
			return (1);
		else
			return (0);
		free(ptr);
		free(ptr2);
	}
	return (-5);
}
