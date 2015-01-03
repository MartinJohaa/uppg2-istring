/*
 * intarray.c
 *
 *  Created on: 8 okt 2014
 *      Author: Dan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define START(p) (p += sizeof(char)*4)
#define STRING(p) (p -= sizeof(char)*4) // Not sure about this
char *istring_mk(const char* str);
void istring_rm(char *str);
char *istring_to_string(const char *str);
size_t istrlen(const char *s);
int istrcmp(const char *s1, const char *s2);
int istrncmp(const char *s1, const char *s2, size_t n);
char *istrchr(const char *s, int c);
char *istrrchr(const char *s, int c);
char* istrslen(char *s, size_t length);
int main() {
  char *string = "Test";
  char *string2 = "TestMedium1111111";
  char *string3 = "TestLong111111111111111111111111111111111111111111111111"
    "111111111111111111111111111111111111111111111111111111111111";
  char *string4 = "TestSuper88888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888888888888888888"
    "8888888888888888888888888888888888888888888888888";
  char *str1 = istring_mk("abcd");
  char *str2 = istring_mk("bcde");
  char *str3 = istring_mk("abcdcef");
  char *str4 = istring_mk("abdc");
  char ctest = 'c';
  // Skolans tester
  char *str5 = istring_mk(NULL);
  printf("Is str5 null? (1:yes, 0:no): %d\n", (str5 == NULL));
  char str6[] = "foo";
  char *str7 = istring_mk(str6);
  printf("Is str7 as long as str6? (1:yes, 0:no): %d\n",
         strlen(str7) == strlen(str6));
  printf("Is str7 equal to str6? (1:yes, 0:no): %d\n",
         strcmp(str6, str7) == 0);
  printf("Is str7[0] equal to 'f'? (1:yes, 0:no): %d\n", str7[0] == 'f');
  printf("Is str7[1] equal to 'o'? (1:yes, 0:no): %d\n", str7[1] == 'o');
  printf("Is str7[2] equal to 'o'? (1:yes, 0:no): %d\n", str7[2] == 'o');
  printf("Is str7[3] equal to NULLSIGN? (1:yes, 0:no): %d\n", str7[3] == '\0');
  printf("%s compared with %s returns: %d\n", str1, str1,
         istrcmp(str1, str1));
  printf("%s compared with %s returns: %d\n", str1, str2,
         istrcmp(str1, str2));
  printf("%s compared with %s returns: %d\n", str1, str3,
         istrcmp(str1, str3));
  printf("%s compared with %s returns: %d\n", str2, str3,
         istrcmp(str2, str3));
  printf("%s N-compared with %s, 2 chars, returns: %d\n", str1, str4,
         istrncmp(str1, str4, 2));
  printf("%s N-compared with %s, 3 chars, returns: %d\n", str1, str4,
         istrncmp(str1, str4, 3));
  printf("Search %s for %c. Printed: %s\n", str3, ctest,
         istrchr(str3, ctest));
  printf("Search Reverse %s for %c. Printed: %s\n", str3, ctest,
         istrrchr(str3, ctest));
  // Allocate istrings in memory
  char *ASDF = istring_mk(string);
  char *ASDF2 = istring_mk(string2);
  char *ASDF3 = istring_mk(string3);
  char *ASDF4 = istring_mk(string4);
  printf("ASDF variable before istring_to_string: %s\n", ASDF);
  char *ASDFstring = istring_to_string(ASDF);
  printf("ASDF variable after istring_to_string (unchanged): %s\n", ASDF);
  printf(
         "New array created from istring_to_string which is of old string type: %s\n",
         ASDFstring);
  printf("The length of string1 is : %ld \n", istrlen(ASDF));
  printf("The length of string2 is : %ld \n", istrlen(ASDF2));
  printf("The length of string3 is : %ld \n", istrlen(ASDF3));
  printf("The length of string4 is : %ld \n", istrlen(ASDF4));
  /*
   * Loops for printing the currently allocated istrings
   */
  /*
    for(int i = 0; i < strlen(ASDF); i++){
    printf("%c ", ASDF[i]);
    }
    printf("\n");
    for(int i = 0; i < strlen(ASDF2); i++){
    printf("%c ", ASDF2[i]);
    }
    printf("\n");
    for(int i = 0; i < strlen(ASDF3); i++){
    printf("%c ", ASDF3[i]);
    }
    printf("\n");
    for(int i = 0; i < strlen(ASDF4); i++){
    printf("%c ", ASDF4[i]);
    }
    printf("\n");
  */
  // Deallocate strings to free memory
  // istring_rm(string);
  // istring_rm(string2);
  // istring_rm(string3);
  // istring_rm(string4);
  istring_rm(str1);
  istring_rm(str2);
  istring_rm(str3);
  istring_rm(str4);
  istring_rm(str5);
  istring_rm(str7);
  istring_rm(ASDF);
  istring_rm(ASDF2);
  istring_rm(ASDF3);
  istring_rm(ASDF4);
  return 0;
}
char *istring_mk(const char* str) {
  /* Allocate memory for temp, where the length of str and the string
     str will be stored and returned. length is the length of str.
     lenarray is the array where the length is stored temporarily.
  */
  int length = (str == NULL) ? 0 : strlen(str);
  if (str == NULL || length > 9999) { // String str was empty or longer than 9999 characters
    return NULL;
  } else {
    char *temp = istrslen(str, length);
    return temp;
  }
}
/*
 * Deallocates str from memory
 */
void istring_rm(char *str) {
  free(str);
}
/*
 * Takes istring str, allocates memory for a new array temp,
 * copies str to temp, moves pointer 4 chars with START macro,
 * returns temp as string type.
 */
char *istring_to_string(const char *str) {
  int length = (strlen(str) + 1) + 4;
  char *temp = malloc(length);
  for (int i = 0; i < length; i++) {
    temp[i] = str[i];
  }
  return temp;
}
/*
 * Inspects the length of the string from str and if it differs from
 * length, updates length accordingly. If str does not contain a \0
 * token, it will be inserted at the first element which is not a
 * printable ascii character, and length updated accordingly. This
 * function must be as efficient as possible and not rescan the string
 * if it can be avoided.
 *
 * This function is useful when istrings have been manipulated as
 * regular C strings, to reestablish the length invariant.
 size_t istrfixlen(char *s); {
 }
*/
/*
 * Sets the length of an istring and inserts a corresponding '\0'
 * character. If the length argument is out of bounds for the string,
 * a new istring should be returned with the contents of the original
 * string. The last character of the original string will be repeated
 * to fill the string to its given length.
 */
char* istrslen(char *s, size_t length) {
  char lenarray[5];
  char *temp = malloc((strlen(s) + 1) + 4);
  sprintf(lenarray, "%zu", length);

  if (length < 10) {
    // Copy length to beginning of temp array
    temp[0] = '0';
    temp[1] = '0';
    temp[2] = '0';
    temp[3] = lenarray[0];
    // Copy str to temp after the first 4 digits
    for (int i = 0; i <= length; i++) {
      temp[i + 4] = s[i];
    }
    START(temp);
    return temp; // Return temp array
  } else if (length < 100 && length >= 10) {
    temp[0] = '0';
    temp[1] = '0';
    temp[2] = lenarray[0];
    temp[3] = lenarray[1];
    for (int i = 0; i <= length; i++) {
      temp[i + 4] = s[i];
    }
    START(temp);
    return temp;
  } else if (length < 1000 && length >= 100) {
    temp[0] = '0';
    temp[1] = lenarray[0];
    temp[2] = lenarray[1];
    temp[3] = lenarray[2];
    for (int i = 0; i <= length; i++) {
      temp[i + 4] = s[i];
    }
    START(temp);
    return temp;
  } else {
    temp[0] = lenarray[0];
    temp[1] = lenarray[1];
    temp[2] = lenarray[2];
    temp[3] = lenarray[3];
    for (int i = 0; i <= length; i++) {
      temp[i + 4] = s[i];
    }
    START(temp);
    return temp;
  }
}
char *istrrchr(const char *s, int c) {
  int length = (strlen(s) + 1) + 4;
  char *temp = malloc(length);
  for (int i = 0; i < length; i++) {
    temp[i] = s[i];
  }
  for (int i = length; i >= 4; i--) {
    if ((s[i]) == c)
      return (temp + i);
  }
  return NULL;
}
char *istrchr(const char *s, int c) {
  int length = (strlen(s) + 1) + 4;
  char *temp = malloc(length);
  for (int i = 0; i < length; i++) {
    temp[i] = s[i];
  }
  for (int i = 0; s[i] != '\0'; i++) {
    if ((s[i]) == c)
      return (temp + i);
  }
  return NULL;
}
int istrncmp(const char *s1, const char *s2, size_t n) {
  int x = 0;
  for (int i = 0; i < (n - 1) && s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] < s2[i])
      return -1;
    if (s1[i] > s2[i])
      return 1;
    x++;
  }
  if (s1[x] < s2[x])
    return -1;
  if (s1[x] > s2[x])
    return 1;
  else
    return 0;
}
int istrcmp(const char *s1, const char *s2) {
  for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
    if (s1[i] < s2[i])
      return -1;
    if (s1[i] > s2[i])
      return 1;
  }
  // när den kommer hit har den läst NULL i ett av strängarna
  if (istrlen(s2) > istrlen(s1))
    return -1;
  if (istrlen(s1) > istrlen(s2))
    return 1;
  else
    return 0;
}
size_t istrlen(const char *s) {
  STRING(s);
  size_t length = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10
    + (s[3] - '0');
  return length;
}
