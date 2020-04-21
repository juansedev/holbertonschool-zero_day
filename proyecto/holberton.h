#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/**
 * struct path_s - singly linked list
 * @full_path_name: name of the paht - (malloc'ed string)
 * @len_path_name: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
	typedef struct path_s
	{
		char *full_path_name;
		unsigned int len_path_name;
		struct path_s *next;
	} path_node;


/* Shell functions shell_functions.c*/
	void non_interact(int ac, char *av[], int *count_exe);
	int interactive(char *av[], int *count_exe);
	char **split_buffer(char *av);
	void create_process(char *filename, char *av[]);
	char *_getenv(char *name);
	void free_arg(char **arguments);

/* funcions search_path path_fuctions.c*/
	path_node *add_node_end(path_node **head, const char *str);
	void convert_path_to_list(path_node **head, char *current_path);
	char *validate_file(const path_node *h, char *file);
	char *search_path(char *av);
	void free_list(path_node **head);

	/* Str functions  str_functions.c*/
	char *_strcpy(char *dest, char *src);
	int _strlen(const char *s);
	char *_strcat(char *dest, char *src);
	char *_strdup(char *str);
	int _strcmp(char *s1, char *s2);

#endif
