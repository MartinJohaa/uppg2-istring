#ifndef ISTRING_H
#define ISTRING_H

#include <string.h>

/*
 * Returns a new istring instance created from supplied
 * string. Returns NULL if out of memory. Returns NULL string if
 * argument str is NULL. 
 */

///
/// Creates an istring.
///
/// @parem the string to be converted into an istring.
/// @return a pointer to the created istring.
char *istring_mk(const char* str);

/*
 * Deallocates the supplied istring.
 */

///
/// Deletes an istring.
///
/// @parem the istring to be deleted
void istring_rm(char *str);

/*
 * Returns a standard null terminated char* representation of the
 * supplied istring. Returns NULL if out of memory.
 */

///
/// Converts an istring to a "normal" string. 
///
/// @parem the istring to be converted.
/// @return a pointer to the new string.
char *istring_to_string(const char *str);

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
 */


///
/// Checks if the length-numbers of an istring is correct, if not correct it updated the numbers.
///
/// @parem the istring to be checked.
/// @return the length of the updated istring.
size_t istrfixlen(char *s);

/* 
 * Sets the length of an istring and inserts a corresponding '\0'
 * character. If the length argument is out of bounds for the string,
 * a new istring should be returned with the contents of the original
 * string. The last character of the original string will be repeated
 * to fill the string to its given length.
 */

///
/// Adds length in a 4-numberformat before the string s.
///
/// @parem the string witch length should be added.
/// @parem the length to be added before s.
/// @return a pointer to the string with the length added.
char* istrslen(char *s, size_t length);

/*
 * For definitions, see the manual page of respective function on the
 * solaris system and the assignment text.
 * 
 * Think about whether having O(1) access to the length can be used to
 * improve the implementations if the string.h equivalents and use
 * that to guide your implementations!
 */

/// 
/// Searching for the char c in the istring s beginning from the end.
/// 
/// @parem the istring to be searched.
/// @parem the ascii value of the char to be searched for.
/// @return a pointer to the string beginning from the first character c (searched from the end) if it is found. Else NULL.
char *istrchr(const char *s, int c);

/// 
/// Searching for the char c in the istring s.
///
/// @parem the istring to be searched.
/// @parem the ascii value of the char to be searched for.
/// @return a pointer to the string beginning from the character c if it is found. Else NULL.
char *istrrchr(const char *s, int c);

///
/// Compares 2 istrings.
///
/// @parem istring #1
/// @parem istring #2
/// @return 0 if the istrings are equal, else bigger or less than 0.
int istrcmp(const char *s1, const char *s2);

///
/// Compares the first n chars in s1 and s2.
///
/// @parem istring #1
/// @parem istring #2
/// @return 0 if the first n chars are equal, else bigger or less than zero.
/// 
int istrncmp(const char *s1, const char *s2, size_t n);

///
/// Checks the length of an istring
///
/// @parem pointer to the istring.
/// @return the length of the istring s.
size_t istrlen(const char *s);

/*
 * I nedanstående funktioner är dst en pekare till en vanlig
 * sträng och inte en istring. Däremot skall minnesutrymmet
 * "konverteras" till en istring av funktionerna, d.v.s. efter att
 * t.ex. istrcpy anropats bör man vid anropsplatsen göra dst =
 * STRING(dst) för att hoppa över längd-delen av strängen.
*/

///
/// Makes a copy of src and puts it in dst.
///
/// @parem pointer to destination
/// @parem pointer to source
/// @return pointer to destination
char *istrcpy(char *dst, const char *src);

///
/// Makes a copy of the first n chars in src and puts it in dst.
///
/// @parem pointer to destination 
/// @parem pointer to source
/// @return pointer to destination
char *istrncpy(char *dst, const char *src, size_t n);

///
/// Appends the istring src to the string dst and updates the length.
/// 
/// @parem the destination string
/// @parem the source istring
/// @return a pointer to the concatted istring 
char *istrcat(char *dst, const char *src);

///
/// Appends n chars of the the istring src to the string dst 
/// and updates the length.
///
/// @parem the destination string.
/// @parem the istring you want to concat to dst.
/// @parem an size_t telling how many chars you want to concat.
/// @return a pointer to the concatted string.
char *istrncat(char *dst, const char *src, size_t n);

#endif
