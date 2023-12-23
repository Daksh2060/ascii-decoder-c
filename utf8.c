#include "utf8.h"

// Function to decode UTF-8 encoded characters
void decode_utf8(const char* s) {

    // Used binary as opposed to hexadecimal for comprehension
    char character = s[0];
    int unicode;

    // First significant byte is 0, char is 1 byte
    if ((character & 0b10000000) == 0) {

        //If single byte, character is in ASCII
        unicode = character;       
    } 

    // First 2 significant bytes are 1, char is 2 bytes
    else if ((character & 0b11100000) == 0b11000000) {
        
        // Find the remaining matching bits for the first byte,
        // then match the next 6 bits for the next byte
        unicode = ((character & 0b00011111) << 6) | (s[1] & 0b00111111);
    } 

    // First 3 significant bytes are 1, char is 3 bytes
    else if ((character & 0b11110000) == 0b11100000) {
        
        // Find the remaining matching bits for the first byte,
        // then match the next 6 bits for the next 2 bytes
        unicode = ((character & 0b00001111) << 12) | ((s[1] & 0b00111111) << 6) | (s[2] & 0b00111111);
    } 

    // First 4 significant bytes are 1, char is 4 bytes
    else if ((character & 0b11111000) == 0b11110000) {
        
        // Find the remaining matching bits for the first byte,
        // then match the next 6 bits for the next 3 bytes
        unicode = ((character & 0b00000111) << 18) | ((s[1] & 0b00111111) << 12) | ((s[2] & 0b00111111) << 6) | (s[3] & 0b00111111);
    } 

    else {
        // Unknown byte
        printf("<li>Unknown byte: 0x%02hhx</li>\n", s[0]);
    }

    //Print out the decimal and unicode values of the character
    if(unicode){

        printf("Decimal Value: %d\n", unicode);
        printf("Unicode Codepoint: U+%04X\n", unicode);
    }

    //Print the name of the character from the DerivedName.txt file
    print_character_name(unicode);
}

// Function to print the character name based on the Unicode code point
void print_character_name(unsigned int codepoint) {

    // Change the file name here
    FILE* file = fopen("DerivedName.txt", "r"); 

    if (file == NULL) {

        perror("Error opening file");
        return;
    }

    // Change the type to unsigned int
    unsigned int current_codepoint; 
    char character_name[256];

    // Read the Unicode code points and character names from the file
    while (fscanf(file, "%X ; %[^\n]", &current_codepoint, character_name) != EOF) {

        if (current_codepoint == codepoint) {

            printf("Character Name: %s\n", character_name);
            break;
        }
    }

    fclose(file);
    fflush(stdout);
}

int main() {
    char input[5];

    // Prompt the user to enter a Unicode character in UTF-8 encoding
    printf("Enter a Unicode character in UTF-8 encoding (input '!' to exit): \n");

    // Continue to read input until '!' is entered
    while (scanf("%4s", input) && input[0] != '!') {
        
        // Call the decode_utf8 function to process the entered UTF-8 encoded character
        decode_utf8(input);

        // Print a separator for better output readability
        printf("\n--------------------------------\n");
    }

    return 0;
}