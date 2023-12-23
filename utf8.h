#include <stdint.h>
#include <stdio.h>

/*
 Prints the character name based on the Unicode code point.
 This function takes a Unicode code point as input, reads the corresponding
 character name from the DerivedName.txt file and prints the character name.
 (Can be switched to another file if given in the format "<codepoint> ; <character name>")
*/
void print_character_name(unsigned int codepoint);

/*
 Decodes UTF-8 encoded characters and prints their Unicode code points.
 This function takes a UTF-8 character as input, decodes the character,
 and prints it's Unicode code points and names. It supports characters encoded
 with 1 to 4 bytes in UTF-8 format.
*/
void decode_utf8(const char* s);
