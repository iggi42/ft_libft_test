#include <libft.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	ft_printf("joas %c joa\n", 'c');
	ft_printf("joas %s joa\n", "servus");
	ft_printf("golden ratio: %d \n",1.61803398875);
	ft_printf("answer: %i\n", 42);
	ft_printf("unsigned decimal answer: %u\n", argc);
	ft_printf("lower hex: %x\n", 0xdeadbeef);
	ft_printf("upper hex: %X\n", 0xbad1dea);
	ft_printf("pointer: %p , null: %p\n", argv, NULL);
	ft_printf("just a %%\n");
	return 0;
}
