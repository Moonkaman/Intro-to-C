#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of 
    characters in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
  int strLen = 0;
  while (*s != '\0')
  {
    s += 1;
    strLen++;
  }
  return strLen;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
  int sLen = string_length(s) - 1;
  int ri = 0;
  printf("The string length is %d\n", sLen);
  printf("The last character is %c\n", *(s + sLen));
  for (int i = sLen; i >= 0; i--)
  {
    rv[ri] = *(s + i);
    ri++;
  }
  rv[ri] = '\0';
  return rv;
}

#ifndef TESTING
int main(void)
{
  char quote1[] = "Don't forget to be awesome";
  char quote2[] = "a man a plan a canal panama";

  char rv[512];

  printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
  printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

  return 0;
}
#endif
