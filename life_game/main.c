#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

char **map;
int raw_number;

void generate_map(void)
{
	map = malloc (sizeof(char *) * (raw_number + 1));
	int i = 0, j = 0;
	while (i < raw_number)
	{
		map[i] = malloc(sizeof(char) * (raw_number + 1));
		while (j < raw_number)
		{
			int tmp = rand() % 2;
			if (tmp == 0)
				map[i][j] = ' ';
			else
				map[i][j] = '*';
			j++;
		}
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	map[i] = NULL;
}

int count_neib(int i, int j)
{
	int count = 0;
	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			if (x == 0 && y == 0)
				continue;
			if (i + x >= 0 && i + x < raw_number && j + y >= 0 && j + y < raw_number)
				count += map[i + x][j + y] == '*';
		}
	}
	return (count);
}

void update_map(void)
{
	char **newmap = malloc(sizeof(char *) * (raw_number + 1));
	int i = 0, j = 0;
	while (i < raw_number)
	{
		newmap[i] = malloc(sizeof(char) * (raw_number + 1));
		while (j < raw_number)
		{
			int neib = count_neib(i,j);
			if (map[i][j] == '*')
			{
				if (neib < 2)
					newmap[i][j] = ' ';
				if (neib == 2 || neib == 3)
					newmap[i][j] = '*';
				else
					newmap[i][j] = ' ';

			}
			else
			{
				if (neib == 3)
					newmap[i][j] = '*';
				else
					newmap[i][j] = ' ';
			}
			j++;
		}
		newmap[i][j] = '\0';
		i++;
		j = 0; 
	}
	for (int i = 0;  i < raw_number; i++)
	{
		free (map[i]);
		map[i] = newmap[i];
	}
	free(newmap);
	return ;
}

bool is_num(char *str)
{
	int i = 0;
	if (str == NULL)
		return (false);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (false);
		i++;
	}
	return (true);
}

int start_program(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	if (is_num(av[1]) == false)
		return (-1);
	raw_number = atoi(av[1]);
	return (0);
}

void disp_map(void)
{
	int i = 0;
	while (i < raw_number)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (start_program(ac, av) == -1)
	{
		printf("%s\n", "usage: ./a.out raw_number(int)");
		return (-1);
	}
	generate_map();
	while (true)
	{
		update_map();
		disp_map();
		usleep(100000);
	}
	return (0);
}
