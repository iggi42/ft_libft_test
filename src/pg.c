#include "../include/ftt.h"
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

// [0] R OUT
// [1] W OUT
// [2] R IN
// [3] W IN
void	ft_pipe_x(void)
{
	int		fds[4];
	int		*f;
	char	result[10];
	int		pid;
	ssize_t	read_res;

	f = (int *)&fds;
	ft_memset(result, 'X', 9);
	(void)pipe(f);
	(void)pipe(f + 2);
	ft_printf("fds: [%d, %d, %d, %d]\n", fds[0], fds[1], fds[2], fds[3]);
	pid = ft_spawn_cmd("echo -n hello", __environ, f + 1);
	read_res = read(fds[0], &result, 7);
	ft_printf("read from pid(%d) via fd(%d) res: %d to [%s]\n", pid, fds[0], read_res, result);
	// waitpid(pid, NULL, 0);
	ft_bzero(fds, 4 * sizeof(int));
	read_res = read(fds[0], &result, 5);
	ft_printf("read from pid(%d) via fd(%d) res: %d to [%s]\n", pid, fds[0], read_res, result);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	ft_pipe_x();
	return (0);
}
