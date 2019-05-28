#include <stdio.h>
#include <string.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
  int i = 0;
  while (*y != '\0')
  {
    x[i] = *y;
    i++;
    y++;
  }
  x[i] = '\0';
  printf("%s\n", x);
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
  int found = 0;
  while (*str != '\0')
  {
    if (*str == c)
    {
      found = 1;
      break;
    }
    str++;
  }
  if (found)
  {
    return str;
  }
  else
  {
    return NULL;
  }
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
  int needLen = strlen(needle) - 1;
  while (*haystack != '\0')
  {
    if (*haystack == *needle)
    {
      int found = 1;
      for (int i = 0; i <= needLen; i++)
      {
        if (*(haystack + i) != *(needle + i))
        {
          found = 0;
          break;
        }
      }
      if (found)
      {
        return haystack;
      }
    }
    haystack += 1;
  }
  return NULL;
}

#ifndef TESTING
int main(void)
{

  char buffer[1024];

  string_copy(buffer, "Hello!");

  char *found_char = find_char("hello", 'e');
  char *found_string = find_string("hey sponpbob, whats up spornbob hey sponge man", "spong");

  printf("Found char: %s\n", found_char);
  printf("Found string: %s\n", found_string);

  return 0;
}
#endif
