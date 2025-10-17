#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	char *src = "qwertzuiop";
	char *dest = strdup("abc\0;123456789;123456789");
  int result = ft_strlcat(dest, src, 14);
  printf("%d \"%s\"\n", result, dest);
}
