#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * infinite_while - Infinite while for manage zombie process in program
 * Void: No entry parameters in prog
 * Return: exit 0 on success
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Main func zombie process in program
 * Void: No entry parameters in program
 * Return: Exit 0 on success
 */
int main(void)
{
	pid_t child_pd;
	int num_of_proc;

	for (num_of_proc = 1; num_of_proc < 6; num_of_proc++)
	{
		child_pd = fork();
		if (child_pd > 0)
		{
			printf("Zombie process created, PID: %d\n", child_pd);
			sleep(1);
		}
		else
		{
			exit(0);
		}
	}
	infinite_while();
	return (0);
}
