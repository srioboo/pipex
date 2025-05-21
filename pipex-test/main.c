/**
 * Executes the command "cat infile | grep Lausanne".  
 */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	//(void) ac;
	//(void) av;
	int pipefd[2];
	int pid;

	pid = 0;
	
	char *cat_args[] = {"/usr/bin/cat", "infile", NULL};
	char *grep_args[] = {"/usr/bin/grep", "Lausanne", NULL};
	
	// make a pipe
	// fds go in pipefd[0] and pipefd[1]
	pid = pipe(pipefd);
	printf("HI %d %d %p %p\n", pid, ac, av, env);
	if (pid == 0)
	{
		// child process gets here and handles "grep Lausanne"
		// replace standard input with input part of the pipe
		printf("HI");
		dup2(pipefd[0], 0);
		
		// close unused half of the pipe
		close(pipefd[1]);
		
		// execute grep
		//execve("/usr/bin/grep", grep_args, env);
		// execute cat
		execve("/usr/bin/cat", cat_args, env);
	}
	else
	{
		printf("ELSE");
		// parent process gets here and handles "cat scores"
		// replace standard output with output part of pipe
		dup2(pipefd[1], 1);
		
		// close unused half of the pipe
		close(pipefd[0]);
		
		// execute cat
		//execve("/bin/cat", cat_args, env);
		execve("/usr/bin/grep", grep_args, env);
	}
	// close unused pipe
	close(pipefd[0]);
	close(pipefd[1]);
	
	// wait for the child process to finish
	int status = 0;
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WIFEXITED(status)) // TODO - more options
		printf("%d",  WEXITSTATUS(status));
	

	return (0);
}