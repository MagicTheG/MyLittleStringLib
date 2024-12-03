#include "./strlib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * tolowercase
 * Converts an uppercase character to its lowercase equivalent.
 * 
 * @param a The character to convert.
 * @return The lowercase version of the character if it is uppercase; 
 * Otherwise, returns the character unchanged.
 * 
 * Example: tolowercase('A') returns 'a', while tolowercase('1') returns '1'.
 */
static char tolowercase(char a)
{
    if (a >= 'A' && a <= 'Z')
    {
        char lowercase = a | 0x20; // Toggle the 6th bit to convert to lowercase
        return lowercase;
    }
    return a;
}

/**
 * strcmp
 * Compares two strings lexicographically.
 *
 * @param a One string to compare.
 * @param b The other string to compare.
 * @return 1 if a > b, -1 if a < b, or 0 if a == b.
 * 
 * The comparison is based on the ASCII values of the characters.
 * The function processes each character until a difference is found
 * or the end of either string is reached.
 */
int strcmp(const char *a, const char *b)
{


    while (*a != '\0' && *b != '\0'){
        char capsA = tolowercase(*a);
        char capsB = tolowercase(*b);

        if (capsA != capsB){
            if (capsA > capsB){
                return 1;
            } 
            else {
                return -1;
            }
        }

        a++;;
        b++;
    }

    if(*a == '\0' && *b == '\0'){
        return 0; // Both would be equal since they ended at the same time.
    }
    else if (*a == '\0'){
        return -1;
    }
    else {
        return 1;
    }
}

/**
 * str_len
 * Calculates the length of a string.
 *
 * @param string The string whose length is to be determined.
 * @return The length of the string, excluding the null terminator.
 *
 * The function iterates through the string until it encounters the null terminator.
 */
int str_len(const char *string)
{
    int totalLength = 0;
    
    while (*string != '\0'){
        totalLength++;
        string++;
    }

    return totalLength; 
    
    
}

/**
 * str_cpy
 * Copies a source string to a destination string.
 *
 * @param dest The destination string to which the source string will be copied.
 * @param src The source string to be copied.
 *
 * The function copies each character from the source string to the destination
 * string and appends a null terminator at the end.
 */
void str_cpy(char *dest, const char *src)
{
    while (*src != '\0'){
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';

}

/**
 * strdup
 * Duplicates a string by allocating memory and copying its content.
 *
 * @param input The string to be duplicated.
 * @return A pointer to the newly allocated duplicate string.
 *
 * The function first calculates the length of the input string, then allocates
 * memory for the new string (including space for the null terminator),
 * and finally copies the input string into the allocated memory.
 */
char *strdup(const char *input)
{
    int length = str_len(input);


    char *newString = malloc(length + 1);
    if (newString == NULL){
        return NULL;
    }

    char *copied = newString;
    while (*input != '\0'){
        *copied = *input;

        copied++;
        input++;

    }

*copied = '\0';


return newString;

}
