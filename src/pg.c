#include "libft_io.h"
#include <sys/wait.h>
#include <unistd.h>

void	piping(void)
{
	int		pipe_fds[2];
	int		fork_res;
	int		*child_res;
	char	*result;

	child_res = NULL;
	ft_printf("pipe return (%d)\n", pipe(pipe_fds));
	fork_res = fork();
	if (fork_res)
	{ // parent part
		ft_putstr_fd("joa, oida\n", pipe_fds[1]);
	}
	else
	{ // child part
		// waitpid(fork_res, child_res, 10);
		result = ft_gnl(pipe_fds[0]);
		ft_printf("result: [%p]\n", child_res);
		if (child_res)
			ft_printf("*result: [%d]\n", *child_res);
		ft_printf("read: [%s]\n", result);
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	piping();
}
