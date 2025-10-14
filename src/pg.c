#include <libft.h>
#include <stdio.h>

int main(void)
{
	int a1[] = {0, 2, 0};
	int a2[] = {0, 2, 3};
  int result = ft_memcmp(a1, a2, 3 * sizeof(int));
	printf("result: %d\n", result);
}
