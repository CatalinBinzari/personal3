
/*
  Name:        test_main.c

  Purpose:     Test string manipulation functions from string.c file
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../src/string.h"

void s_len_valid(void **state);
void find_char_beginning(void **state);
void find_char_middle(void **state);
void find_char_end(void **state);
void find_char_no_char(void **state);
void get_index_valid(void **state);
void get_index_no_adress(void **state);
void trim_vowel_valid(void **state);
void trim_vowel_all_vowels(void **state);
void trim_vowel_no_vowels(void **state);
void is_palindrome_valid_odd(void **state);
void is_palindrome_valid_even(void **state);
void is_palindrome_false(void **state);
/*****************************************************************************/
/*                                                                           */
/*****************************************************************************/

int main()
{
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(s_len_valid),
      cmocka_unit_test(find_char_beginning),
      cmocka_unit_test(find_char_middle),
      cmocka_unit_test(find_char_end),
      cmocka_unit_test(find_char_no_char),
      cmocka_unit_test(get_index_valid),
      cmocka_unit_test(get_index_no_adress),
      cmocka_unit_test(trim_vowel_valid),
      cmocka_unit_test(trim_vowel_all_vowels),
      cmocka_unit_test(trim_vowel_no_vowels),
      cmocka_unit_test(is_palindrome_valid_odd),
      cmocka_unit_test(is_palindrome_valid_even),
      cmocka_unit_test(is_palindrome_false),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

/*
  Name:        s_len_valid

  Purpose:     Test function s_len for valid result

  Params:      IN    state
              
  Returns:     Nothing
*/
void s_len_valid(void **state)
{
  int i = s_len("test");

  assert_int_equal(i, 4);
} /* s_len_valid */

/*
  Name:        find_char_beginning

  Purpose:     Test function find_char for valid result
               with pointer at the beginning

  Params:      IN    state
              
  Returns:     Nothing
*/
void find_char_beginning(void **state)
{
  char *var = "esare";
  char *t = find_char("e",var);

  assert_ptr_equal(t, var);
} /* find_char_beginning */

/*
  Name:        find_char_middle

  Purpose:     Test function find_char for valid result
               with pointer at the middle

  Params:      IN    state
              
  Returns:     Nothing
*/
void find_char_middle(void **state)
{
  char *var = "esare";
  char *t = find_char("a",var);

  assert_ptr_equal((t-2), var);
} /* find_char_middle */

/*
  Name:        find_char_end

  Purpose:     Test function find_char for valid result
               with pointer at the end

  Params:      IN    state
              
  Returns:     Nothing
*/
void find_char_end(void **state)
{
  char *var = "esaret";
  char *t = find_char("t",var);

  assert_ptr_equal((t-5), var);
} /* find_char_end */

/*
  Name:        find_char_no_char

  Purpose:     Test function find_char for invalid result
               if char is not found

  Params:      IN    state
              
  Returns:     Nothing
*/
void find_char_no_char(void **state)
{
  char *var = "esaret";
  char *t = find_char("p",var);
  
  assert_ptr_equal(t, NULL);
} /* find_char_no_char */

/*
  Name:        get_index_valid

  Purpose:     Test function get_index for valid result
               in case of address is veridic

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_index_valid(void **state)
{
  char *var = "esare";
  char *t = find_char("r",var);
  int index = get_index(t, var);
  
  assert_int_equal(index, 3);
} /* get_index_valid */

/*
  Name:        get_index_no_adress

  Purpose:    Test function get_index for invalid result
              in case of address is not veridic

  Params:      IN    state
              
  Returns:     Nothing
*/
void get_index_no_adress(void **state)
{
  char *var = "esare";
  char *t = "y";
  int index = get_index(t, var);
  
  assert_int_equal(index, -1);
} /* get_index_no_adress */

/*
  Name:        trim_vowel_valid

  Purpose:    Test function trim_vowel for valid result
              in case of vowel presence

  Params:      IN    state
              
  Returns:     Nothing
*/
void trim_vowel_valid(void **state)
{
  char *var = "esare";
  char *t = malloc(strlen(var));;
  trim_vowel(var, t);
  
  assert_string_equal(t, "sr");
  free(t);
} /* trim_vowel_valid */

/*
  Name:        trim_vowel_all_vowels

  Purpose:    Test function trim_vowel for valid result
              in case of if all chars are vowels

  Params:      IN    state
              
  Returns:     Nothing
*/
void trim_vowel_all_vowels(void **state)
{
  char *var = "aeiou";
  char *t = malloc(strlen(var));;
  trim_vowel(var, t);
  
  assert_string_equal(t, "");
  free(t);
} /* trim_vowel_all_vowels */

/*
  Name:        trim_vowel_no_vowels

  Purpose:    Test function trim_vowel for valid result
              in case of if chars aren't vowels

  Params:      IN    state
              
  Returns:     Nothing
*/
void trim_vowel_no_vowels(void **state)
{
  char *var = "wdfghj";
  char *t = malloc(strlen(var));;
  trim_vowel(var, t);
  
  assert_string_equal(t, "wdfghj");
  free(t);
} /* trim_vowel_no_vowels */

/*
  Name:        is_palindrome_valid

  Purpose:    Test function is_palindrome for valid result
              if string is palindrome with odd chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_palindrome_valid_odd(void **state)
{
  char *var = "aba";
  bool b = is_palindrome(var);
  
  assert_true(b);
} /* is_palindrome_valid */

/*
  Name:        is_palindrome_valid_even

  Purpose:    Test function is_palindrome for valid result
              if string is palindrome with even chars

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_palindrome_valid_even(void **state)
{
  char *var = "abba";
  bool b = is_palindrome(var);
  
  assert_true(b);
} /* is_palindrome_valid_even */

/*
  Name:        is_palindrome_false

  Purpose:    Test function is_palindrome for valid result
              if string is not palindrome

  Params:      IN    state
              
  Returns:     Nothing
*/
void is_palindrome_false(void **state)
{
  char *var = "abbra";
  bool b = is_palindrome(var);
  
  assert_false(b);
} /* is_palindrome_false */


