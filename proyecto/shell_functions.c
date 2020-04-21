#include "holberton.h"

/**
 * interactive - This function get command line a through getline in the mode
 * interactive and non-interactive mode (echo / cat).
 * @av: Pointer to strings with the Name of the function executed
 * in the first position.
 * @count_exe: Count how many times you receive a command to execute.
 * Return: status_exit value.
 **/
int interactive(char *av[], int *count_exe)
{
	int interactive = 1, start = 1;
	ssize_t read = 0;
	size_t len = 0;
	char *line = NULL;
	char **args = NULL;
	int *count = count_exe;
	(void)av;

	while (start)
	{
		isatty(STDIN_FILENO) == 0 ? interactive = 0 : interactive;
		interactive == 1 ? write(STDIN_FILENO, "#cisfun$ ", 9) : interactive;
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			interactive == 1 ? write(STDIN_FILENO, "\n", 1) : read;
			return (0);
		}
		if (*line != '\n')
		{
			args = split_buffer(line);
			free_arg(args);
		}
		*count = *count + 1;
		free(line);
		printf("count: %d\n", *count);
	}
	return (0);
}

/**
 * non_interact - This function get command line a through arguments of main.
 * @ac: Amount of arguments.
 * @av: Pointer to strings with all arguments of input in each postiion.
 * @count_exe: Count how many times you receive a command to execute.
 * Return: void.
 **/
void non_interact(int ac, char *av[], int *count_exe)
{
	(void)ac;
	(void)av;
	(void)count_exe;
}

/**
 * split_buffer - This function splits the argument input in each
 * part that contains and adds NULL at the final position.
 * @av: Pointer to strings with all arguments of buffer.
 * Return: Pointer to an array of strings with all arguments of input buffer
 * in each postiion.
 **/
char **split_buffer(char *av)
{
	int i = 0, j = 0, lenght = 0;
	char *token = NULL, **array = NULL;
	char *get_buffer = malloc(sizeof(char) * _strlen(av) + 1);

	if (get_buffer == NULL)
		return (NULL);
	strcpy(get_buffer, av);
	token = strtok(av, " \t\n\r");
	while (token != NULL)
	{
		lenght++;
		token = strtok(NULL, " \t\n\r");
	}
	array = malloc(sizeof(char *) * (lenght + 1));
	if (array == NULL)
	{
		free(get_buffer);
		return (NULL);
	}
	i = 0;
	token = strtok(get_buffer, " \t\n\r");
	while (token != NULL)
	{
		array[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (array[i] == NULL)
		{
			for (j = 0; array[j]; j++)
				free(array[j]);
			free(array);
			free(get_buffer);
			return (NULL);
		}
		_strcpy(array[i], token);
		token = strtok(NULL, " \t\n\r");
		i++;
	}
	array[i] = NULL;
	free(get_buffer);
	return (array);
}

/**
 * create_process - This function create a child process and executes
 * a specific program.
 * @filename: Name of the file to validate its exists into the directories
 * and execute.
 * @av: Pointer to an array of strings with all arguments of input buffer
 * in each postiion.
 * Return: void
 **/
void create_process(char *filename, char *av[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(filename, av, NULL) == -1)
		{
			perror("->Error:");
		}
	}
	else
	{
		wait(&status);
	}
}


/**
 * _getenv - get variable enviriomment
 * @name: name the variable envirionment
 * Return: char value envirionment
 **/
char *_getenv(char *name)
{
	char *token1 = NULL, *token2 = NULL;
	char *env_name = NULL;
	int i = 0;

	env_name = _strdup(name);

	while (environ[i])
	{
		token1 = strtok(environ[i], "=");
		token2 = strtok(NULL, "=");
		if (_strcmp(env_name, token1) == 0)
			return (token2);
		i++;
	}
	return (NULL);
}

void free_arg(char **arguments)
{
	int i = 0;

	while (arguments[i] && arguments)
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
