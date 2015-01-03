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


/*
char *istring_mk(const char* str);
void istring_rm(char *str);
char *istring_to_string(const char *str);
size_t istrlen(const char *s);
int istrcmp(const char *s1, const char *s2);
int istrncmp(const char *s1, const char *s2, size_t n);
char *istrchr(const char *s, int c);
char *istrrchr(const char *s, int c);
*/





char *istring_mk(const char* str){
  /* Allocate memory for temp, where the length of str and the string
     str will be stored and returned. length is the length of str.
     lenarray is the array where the length is stored temporarily.
   */
  char *temp = malloc((strlen(str) + 1) + 4);
  int length = strlen(str);
  char lenarray[5];
  sprintf(lenarray,"%d",length);
  if (str == NULL || length > 9999){ // String str was empty or longer than 9999 characters
    return NULL;
    printf("Null.");
  }else {
    if(length < 10){
      // Copy length to beginning of temp array
      temp[0] = '0';
      temp[1] = '0';
      temp[2] = '0';
      temp[3] = lenarray[0];
      // Copy str to temp after the first 4 digits
      for(int i = 0; i <= length; i++){
        temp[i+4] = str[i];
      }
      return temp; // Return temp array
    }
    else if(length < 100 && length >= 10){
      temp[0] = '0';
      temp[1] = '0';
      temp[2] = lenarray[0];
      temp[3] = lenarray[1];
      for(int i = 0; i <= length; i++){
        temp[i+4] = str[i];
      }
      return temp;
    }
    else if(length < 1000 && length >= 100){
      temp[0] = '0';
      temp[1] = lenarray[0];
      temp[2] = lenarray[1];
      temp[3] = lenarray[2];
      for(int i = 0; i <= length; i++){
        temp[i+4] = str[i];
      }
      return temp;
    }
    else {
      temp[0] = lenarray[0];
      temp[1] = lenarray[1];
      temp[2] = lenarray[2];
      temp[3] = lenarray[3];
      for(int i = 0; i <= length; i++){
        temp[i+4] = str[i];
      }
      return temp;
    }
  }
}
/*
 * Deallocates str from memory
 */
void istring_rm(char *str){
  free(str);
}
/*
 * Takes istring str, allocates memory for a new array temp,
 * copies str to temp, moves pointer 4 chars with START macro,
 * returns temp as string type.
 */
char *istring_to_string(const char *str){
    int length = (strlen(str) + 1) + 4;
    char *temp = malloc(length);
    for(int i = 0; i < length; i++){
        temp[i] = str[i];
    }
    START(temp);
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
char* istrslen(char *s, size_t length);{
}
*/


char *istrchr(const char *s, int c){
  int length = (strlen(s) + 1) + 4;
  char *temp = malloc(length);
  for(int i = 0; i < length; i++){
    temp[i] = s[i];
  }
  for(int i = 4; s[i] != '\0'; i++){
    if(s[i] == c) return (temp + i);
  }
  return NULL;
}

char *istrrchr(const char *s, int c){
  int length = (strlen(s) + 1) + 4;
  char *temp = malloc(length);
  for(int i = 0; i < length; i++){
    temp[i] = s[i];
  }
  for (int i = length; i >= 4; i--)
    {
      if (s[i] == c)
        {
          return (temp+i);
        }
    }
  return NULL;
}




int istrncmp(const char *s1, const char *s2, size_t n){
  int x = 4;
  for(int i = 4; i < (n+3) && s1[i] != '\0' && s2[i] != '\0';i++){
    if(s1[i] < s2[i]) return -1;
    if(s1[i] > s2[i]) return 1;
    x++;
  }
  if(s1[x] < s2[x]) return -1;
  if(s1[x] > s2[x]) return 1;
  else return 0;
}     



int istrcmp(const char *s1, const char *s2){
  int x = 4;  
  for(int i = 4; s1[i] != '\0' && s2[i] != '\0'; i++){
    if(s1[i] < s2[i]) return -1;
    if(s1[i] > s2[i]) return 1;
    x++;  
  }
  if(s1[x] < s2[x]) return -1;
  if(s1[x] > s2[x]) return 1;
  else return 0;
}



size_t istrlen(const char *s){
  size_t length = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') *10 + (s[3] - '0')  ;
  return length;
};

int main(int argc, char *argv[])
{
  
  return 0;
}
