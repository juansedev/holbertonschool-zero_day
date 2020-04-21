#include "holberton.h"

/**
 * main - shell proyect
 * @ac: count arguments
 * @av: store arguments
 * Return: estatus_exit value;
 **/

int main(int ac, char *av[])
{
	/*Int conteo de  ejecuciones;*/
	int count_exe = 0, status_exit = 0;

	if (ac > 1)
	{
		non_interact(ac, av, &count_exe);
	}
	else
	{
		status_exit = interactive(av, &count_exe);
		return (status_exit);
	}

	
	return (0);
}
