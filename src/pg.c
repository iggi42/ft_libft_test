#include <libft.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	const char *haystack = "a23";
	const char *needle = "2";

	printf("penis %p %p\n",  needle + 1, ft_strnstr(haystack, needle, 4)	);
}
