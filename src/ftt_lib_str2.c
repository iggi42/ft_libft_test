#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <libft.h>
#include <string.h>
#include <limits.h>

#define T(a) Test(libft_str2, a)

T(substr_easy)
{
 const char *base = "12345678";
 const char *result = ft_substr(base, 0, 3);
 cr_assert_eq(strncmp("123", result, 4), 0, "\"%s\" is not \"123\"", result);
 cr_assert_eq(strlen(result), 3);
}

T(substr_size_too_large)
{
 const char *base = "1";
 const char *result = ft_substr(base, 0, 3);
 cr_assert_eq(strncmp("1", result, 3), 0, "\"%s\" is not \"1\"", result);
 cr_assert_eq(strlen(result), 1);
}

T(substr_start_too_large)
{
 const char *base = "";
 const char *result = ft_substr(base, 1, 3);
 cr_assert_eq(strncmp("", result, 3), 0, "\"%s\" is not an empty string", result);
 cr_assert_eq(strlen(result), 0);
}

T(substr_start_too_large2)
{
 const char *base = "zxy abc efg ";
 const char *result = ft_substr(base, 13, 3);
 cr_assert_eq(strncmp("", result, 3), 0, "\"%s\" is not an empty string", result);
 cr_assert_eq(strlen(result), 0);
}

T(substr_middle)
{
 const char *base = "zxy abc efg ";
 const char *result = ft_substr(base, 4, 3);
 cr_assert_eq(strncmp("abc", result, 3), 0, "\"%s\" is not an empty string", result);
 cr_assert_eq(strlen(result), 3);
}
	
T(substr_last_char)
{
 const char *base = "abc1";
 const char *result = ft_substr(base, 3, 3);
 cr_assert_eq(strncmp("1", result, 3), 0, "\"%s\" the last char of \"%s\" ", result, base);
 cr_assert_eq(strlen(result), 1);
}

T(strjoin_easy)
{
 const char *base = ft_strjoin("4", "2");
 cr_assert_str_eq(base, "42");
}
 
T(strjoin_empty)
{
 const char *base = ft_strjoin("", "");
 cr_assert_str_eq(base, "");
}

T(strjoin_smoll)
{
 const char *base = ft_strjoin("a", "");
 cr_assert_str_eq(base, "a");
}

T(strtrim_easy)
{
 const char *set = "0123456789";
 const char *s1 = "0Eins1Zwei2Drei3Fier4";
 const char *result = ft_strtrim(s1, set);
 cr_assert_str_eq("Eins1Zwei2Drei3Fier", result);
}

T(strtrim_empty)
{
 const char *set = "0123456789";
 const char *s1 = "";
 const char *result = ft_strtrim(s1, set);
 cr_assert_str_eq("", result);
}

T(strtrim_empty2)
{
 const char *set = "0123456789";
 const char *s1 = "jkjk";
 const char *result = ft_strtrim(s1, set);
 cr_assert_str_eq("jkjk", result);
}
