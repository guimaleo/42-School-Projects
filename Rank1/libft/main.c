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
	printf("\033[1;32m\nMemory Tests\n\033[0m\n");
	if ((ft_memory_tester(65)))
		printf("ft_memset: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_memset: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	if (ft_memory_tester(0))
		printf("ft_bzero: \033[1;36mOK!\033[0m\n");
	else
		printf("ft_bzero: \033[1;35mKO!!! Let's talk about it...\033[0m\n");
	char	s[] = "             I have exactly 5 words!           ";
	if ((count_words(s, 32) == 5))
			printf("ft_count_words: \033[1;36mOK!\033[0m\n");
	else
			printf("ft_count_words: \033[1;35mKO!!! Let's talk about it...\033[0m\n");

	printf("\033[1;32m\nFile Descriptor Tests\n\033[0m\n");

	int		fd[2];
	fd[0] = open("./fd_res.txt", O_CREAT | O_RDWR, 0742);
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


	fd[0] = open("./fd_res2.txt", O_WRONLY | O_CREAT, 0742);
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
		fd[0] = open("./fd_nbr.txt", O_CREAT | O_WRONLY, 0742);
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
	fd[0] = open("char.txt", O_CREAT | O_WRONLY, 0742);
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

	p = malloc(10);
	rip = malloc(10);
	if (x != 0)
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
	else
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
}

