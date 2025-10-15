
#include "../include/ftt.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <stdio.h>
#include <libft.h>
#include <string.h>
#include <limits.h>

#define T(a) Test(libft_str2, a)


// TODO check if the string is actually max len (3 in this)
T(substr_easy)
{
 char *base = "12345678";
 char *result = ft_substr(base, 0, 3);
 cr_assert_eq(strncmp("123", result, 4), 0);
}
