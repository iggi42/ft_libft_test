#include "libft_io.h"
#include "libft_mem.h"
#include "libft_os.h"
#include <sys/wait.h>
#include <unistd.h>

int	piping(void)
{
	int		pipe_fds[2];
	int		fork_res;
	int		*child_res;
	char	*result;

	child_res = ft_malloc(sizeof(int));
	*child_res = -1;
	ft_printf("pipe return (%d)\n", pipe(pipe_fds));
	fork_res = fork();
	if (fork_res)
	{ // parent part
		waitpid(fork_res, child_res, 10);
		result = ft_gnl(pipe_fds[0]);
		ft_printf("result: [%p]\n", child_res);
		if (child_res)
			ft_printf("*result: [%d]\n", *child_res);
		ft_printf("read: [%s]\n", result);
	}
	else
	{ // child part
		ft_putstr_fd("joa, oida\n", pipe_fds[1]);
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	if (child_res)
		return (*child_res);
	else
		return (-420);
}

void	spawn_test(void)
{
	int		pipes[2];
	char	*s;
	int		pid;
	char	*l;

	// int res;
	s = "echo hello";
	pid = ft_spawn_cmd(s, __environ, (int **)&pipes);
	ft_printf("pid: %d\n", pid);
	// waitpid(pid, &res, 0);
	l = ft_gnl(pipes[0]);
	ft_printf("line: \"%s\"\n", l);
	close(pipes[0]);
	close(pipes[1]);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	spawn_test();
	return (0);
}
