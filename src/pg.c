#include "libft_arr.h"
#include "libft_io.h"
#include "libft_mem.h"
#include "libft_str.h"
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

#include "libft_kv.h"

static int	str_key_cmp(t_kv_key k1, t_kv_key k2)
{
	return (ft_strncmp((const char *)k1, (const char *)k2, 10));
}

static void	*print_str(void *s)
{
	if (s == NULL)
		s = "[NULL]";
	ft_putstr_fd(s, 1);
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	char	*key1;
	char	*key2;
	char	*val1;
	char	*val2;
	t_kv	*store;
	char	**act_keys;

	key1 = "key34";
	key2 = "key2";
	val1 = "42";
	val2 = "34";
	ft_printf("joa geh\n");
	store = ft_kv_init(str_key_cmp);
	ft_kv_put(store, key1, val1);
	ft_kv_put(store, key2, val2);
	act_keys = (char **)ft_kv_keys(store);
	ft_arr_each((arr_t)act_keys, print_str);
	ft_arr_each((arr_t)act_keys, print_str);
	(void)argc;
	(void)argv;
	(void)env;
	return (0);
}
