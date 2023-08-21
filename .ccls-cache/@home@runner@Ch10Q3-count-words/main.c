// This program counts the number of words in a piece of text

#include <stdio.h>
#include <stdbool.h>

// Declare Functions
bool alphabetic (const char);
void readLine (char[]);
int countWords (const char []);
bool numeric (const char);
int countNumbers (const char []);
int countWordsAndNumbers (const char[]);

int main(void) {

  // Declare Variables
  char text [81];
  int totalWords = 0;
  bool endOfText = false;

  // Get input
  printf ("Type in your text.\n");
  printf ("When you are done, press 'RETURN'.\n\n");

  // Count words
  while ( !endOfText ) {
    readLine (text);

    if (text[0] == '\0')
      endOfText = true;
    else
      totalWords += countWordsAndNumbers (text);
  }

  // Print output
  printf ("\nThere are %d words in the above text.\n", totalWords);
  
  return 0;
}

// Define Functions
bool alphabetic (const char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    return true;
  else
    return false;
}

void readLine (char buffer[]) {
  char character;
  int i = 0;

  do {
    character = getchar ();
    buffer [i] = character;
    i++;
  } 
  while (character != '\n');

  buffer[i - 1] = '\0';
}

int countWords (const char string[]) {
  int i, wordCount = 0;
  bool lookingForWord = true;

  for (i = 0; string[i] != '\0'; i++) {
    if (alphabetic(string[i]) || string[i] == '\'') {
      if (lookingForWord) {
        wordCount++;
        lookingForWord = false;
      }
    }
    else {
      lookingForWord = true;
    }
  }
  return wordCount;
}

bool numeric (const char c) {
  if (0 <= c && c >= 9) 
    return true;
  else
    return false;
}

int countNumbers (const char string[]) {
  int i, numberCount = 0;
  bool lookingForNumber = true;

  for (i = 0; string[i] != '\0'; i++) {
    if (numeric(string[i]) || string[i] == ',' || string[i] == '.') {
      if (lookingForNumber) {
        numberCount++;
        lookingForNumber = false;
      }
    }
    else {
      lookingForNumber = true;
    }
  }
  return numberCount;
}

int countWordsAndNumbers (const char string[]) {
  int numWordsAndNumbers = 0;
  
  numWordsAndNumbers += countWords (string);
  numWordsAndNumbers += countNumbers (string);

  return numWordsAndNumbers;
}