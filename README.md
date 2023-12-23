# Unicode Decoder

This C-based Unicode Decoder offers a straightforward solution for decoding Unicode characters. Whether it's a character within ASCII or the UTF-8 extension, the program swiftly provides essential information such as the Unicode code point, decimal value, and official character name. Unlike relying on Google searches, which may misinterpret characters and often lack all three pieces of aforementioned information in one place, this Unicode Decoder ensures a more efficient and faster way to obtain accurate details once set up and running.

## Features

- **ASCII Character Decoding:** Reads decimal value of ASCII characters by casting input `char` as `int`. Allows for faster searching of name index than UTF-8 characters.  

- **UTF-8 Character Decoding:** Analyzes the first byte of input `char` to determine variable byte length of the character, then decodes each subsequent byte to generate decimal value and unicode code point to search name index.

## How does it work?



![](images/)



## Installation and Use

Follow these steps to set up and run the Multithreaded Network Chat in C:

1. Clone the repository to your local machine:

   ```bash
   git clone 
   ```



## Contact

Feel free to reach out if you have any questions, suggestions, or feedback:

- **Email:** dpa45@sfu.ca
- **LinkedIn:** [@Daksh Patel](https://www.linkedin.com/in/daksh-patel-956622290/)