#include <criterion/criterion.h>
#include <libft.h>
#include <string.h>
#include <limits.h>
#include "../include/ftt.h"

#define T(a) Test(libft_test_meta, a)


T(array_length2)
{
  char* dummy_string = "noooooothing matters";
  char* arr[3];
  arr[0] = dummy_string;
  arr[1] = dummy_string;
  arr[2] = NULL;
  size_t result = ftt_array_lenth(arr, sizeof(char *));
  cr_assert_eq(result, 2);
}


T(array_length0)
{
  char* arr[3];
  arr[0] = NULL;
  size_t result = ftt_array_lenth(arr, sizeof(char *));
  cr_assert_eq(result, 0);
}


T(array_length1)
{
  char* arr[3];
  arr[0] = "penis";
  arr[1] = NULL;
  size_t result = ftt_array_lenth(arr, sizeof(char *));
  cr_assert_eq(result, 1);
}
