#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

size_t	test1(void)
{
	char		b[100];
	t_iol_el	eins = {.buffer = ((char *)b), .size = 1, .free;
	t_iol_el	eins_zwei = {.buffer = ((char *)b), .size = 2, .free;
	t_iol_el	aca = {.buffer = ((char *)b) + 10, .size = 3, .free;
	t_list		first = {.content = &eins, .next;
	t_list		secound = {.content = &eins_zwei, .next;

	b[0] = '1';
	b[1] = '2';
	b[10] = 'A';
	b[11] = 'c';
	b[12] = 'A';
	eins = {.buffer = ((char )b), .size = 1, .free = NULL};
	eins_zwei = {.buffer = ((char )b), .size = 2, .free = NULL};
	aca = {.buffer = ((char )b) + 10, .size = 3, .free = NULL};
	t_list pre = {
		.content = &aca,
		.next = NULL,
	};
	first = {.content = &eins, .next = &pre};
	secound = {.content = &eins_zwei, .next = &first};
	return (ft_iol_size(&secound));
}

// #define test_printf(a, ...) printf("STATUS [%s]: %s\n", ((ft_printf(a,
				##__VA_ARGS__) == printf(a,  ##__VA_ARGS__)) ? " OK " : "NOPE"),
	a);

#define test_printf(a, ...) ft_printf(a, ##__VA_ARGS__);

int	printf_test(int argc, char **argv)
{
	test_printf("joas %c joa\n", 'c');
	test_printf("joas %s joa\n", "servus");
	test_printf("answer: %i\n", 42);
	test_printf("unsigned decimal answer: %u\n", argc);
	test_printf("lower hex: %x\n", 0xdeadbeef);
	test_printf("upper hex: %X\n", 0xbad1dea);
	test_printf("pointer: %p , null: %p\n", argv, NULL);
	test_printf("just a %%\n");
	return (-1);
}
#include <libft_arr.h>
#include <libft_kv.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	char		*key1;
	char		*key2;
	char		*val1;
	char		*val2;
	char		*keys[] = {key1, key2, NULL};
	t_kv_store	*store;
	char		**act_keys;

	(void)argc;
	(void)argv;
	key1 = "key34";
	key2 = "key2";
	val1 = "42";
	val2 = "34";
	ft_printf("[%d]\n", ft_arr_len(keys));
	store = ft_kv_init();
	ft_kv_put(store, key1, val1);
	ft_kv_put(store, key2, val2);
	act_keys = (char **)ft_kv_keys(store);
	ft_printf("[%d]\n", ft_arr_len(act_keys));
	ft_printf("[%d]\n", ft_lstsize(*store));
}
