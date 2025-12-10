#include <libft.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

size_t test1(void){
 char b[100];
 b[0] = '1';
 b[1] = '2';
 b[10] = 'A';
 b[11] = 'c';
 b[12] = 'A';

 t_iol_el eins = { .buffer = ((char *) b), .size = 1, .free = NULL };
 t_iol_el eins_zwei = { .buffer = ((char *) b), .size = 2, .free = NULL };
 t_iol_el aca = { .buffer = ((char *) b) + 10, .size = 3, .free = NULL };

 t_list pre = {
  .content =  &aca,
  .next = NULL,
 };
 t_list first = {
  .content = &eins,
  .next = &pre
 };
 t_list secound = {
  .content = &eins_zwei,
  .next = &first
 };
 return ft_iol_size(&secound);
}

// #define test_printf(a, ...) printf("STATUS [%s]: %s\n", ((ft_printf(a, ##__VA_ARGS__) == printf(a,  ##__VA_ARGS__)) ? " OK " : "NOPE"), a);

#define test_printf(a, ...) ft_printf(a, ##__VA_ARGS__);

int printf_test(int argc, char **argv)
{
	test_printf("joas %c joa\n", 'c');
	test_printf("joas %s joa\n", "servus");
	test_printf("answer: %i\n", 42);
	test_printf("unsigned decimal answer: %u\n", argc);
	test_printf("lower hex: %x\n", 0xdeadbeef);
	test_printf("upper hex: %X\n", 0xbad1dea);
	test_printf("pointer: %p , null: %p\n", argv, NULL);
	test_printf("just a %%\n");
	return -1;
}
#include <limits.h>

int main(int argc, char **argv)
{
 (void) argv;
	int *a = (int *) malloc(sizeof(int) * argc);
	int *b = (int *) malloc(sizeof(int) * argc);
	int *c = (int *) malloc(sizeof(int) * argc);
	ft_printf("return value %p\n", ft_free(&a, &b, &c));
	ft_printf("[%p %p %p]\n", a, b, c);
}

