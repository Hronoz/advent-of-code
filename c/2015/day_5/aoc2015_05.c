#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define AOCYEAR 2015
#define AOCDAY 5

#define MAXLINELENGTH 32

bool is_string_nice(char *str);
int is_vowel(char ch);
bool is_forbidden_character(char ch);

int main()
{
    char buffer[MAXLINELENGTH];
    unsigned int nice_strings_count = 0;
    while (fgets(buffer, MAXLINELENGTH, stdin))
        nice_strings_count += is_string_nice(buffer);

    printf("%4d-%02d/%d: %d\n", AOCYEAR, AOCDAY, 1, nice_strings_count);

    return 0;
}

bool is_string_nice(char *str)
{
    unsigned int vowels_count = 0; /* should be at least 3 */

    char *current = str, *next = (str + 1);

    /* true if string has at least one pair of same characters in a row */
    bool contains_letter_twice = false; 
    /* true if string has a pair of ab, cd, pq, or xy in it */
    bool contains_forbidden_pair = false;

    while (*current != '\0')
    {
        vowels_count += is_vowel(*current);

        if (!contains_letter_twice) 
            contains_letter_twice = *current == *next;


        if (!contains_forbidden_pair)
            contains_forbidden_pair = is_forbidden_character(*current)
                && (*current + 1 == *next);


        ++current;
        ++next;
    }

    return (vowels_count >= 3) && (contains_letter_twice) 
        && (!contains_forbidden_pair);
}

int is_vowel(char ch)
{
    switch (ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
    }
}

bool is_forbidden_character(char ch)
{
    switch (ch)
    {
        case 'a':
        case 'c':
        case 'p':
        case 'x':
            return true;
        default:
            return false;
    }
}
