#include "../include/ftt.h"
#include <criterion/criterion.h>
#include <limits.h>
#include <string.h>

#define T(a) Test(libft_test_meta, a)

T(array_length2)
{
	char	*dummy_string;
	char	*arr[3];
	size_t	result;

	dummy_string = "noooooothing matters";
	arr[0] = dummy_string;
	arr[1] = dummy_string;
	arr[2] = NULL;
	result = ftt_array_lenth(arr, sizeof(char *));
	cr_assert_eq(result, 2);
}

T(array_length0)
{
	char	*arr[3];
	size_t	result;

	arr[0] = NULL;
	result = ftt_array_lenth(arr, sizeof(char *));
	cr_assert_eq(result, 0);
}

T(array_length1)
{
	char	*arr[3];
	size_t	result;

	arr[0] = "penis";
	arr[1] = NULL;
	result = ftt_array_lenth(arr, sizeof(char *));
	cr_assert_eq(result, 1);
}
