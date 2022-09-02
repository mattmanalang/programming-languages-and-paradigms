#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cctype>
#include <map>
#include "ArgumentManager.h" 
// This ArgumentManager is a command line argument parser that was used in the Data Structures course with Dr. Rizk. 
// It assumes the command line argument be formatted exactly as such: "input=filename1.txt;output=filname2.txt"
// The format of the command line arguments for this homework fits the format of the ArgumentManager.

using namespace std;

void checkNumberOfArgs(int argc) {
  if (argc == 1) {
    cout << "Error: No arguments were passed. Please provide an argument for input and output files." << endl;
    exit(1);
  }
}

bool isOnlyAlpha(string word) {
  for (char character : word) {
    if (!isalpha(character)) {
      return false;
    }
  }
  return true;
}

map<string, int> tallyWords(ifstream& inputFile) {
  map<string, int> wordCountTable;
  string word;
  
  while (inputFile >> word) {
    if (!isOnlyAlpha(word) || word.size() < 1) {
      continue;
    }
    wordCountTable[word]++;
  }

  return wordCountTable;
}

int main(int argc, char const *argv[])
{
  checkNumberOfArgs(argc);
  ArgumentManager argManager(argc, argv);
  const string inputFilename = argManager.get("input");
  const string outputFilename = argManager.get("output");

  ifstream inputFile(inputFilename);
  // Idea: have a string stream to build the characters read in from the file because there are delimiters of different types.
  // Idea 2: use a dictionary, map, etc. to store the words found as well as the number of times that they have occurred.
  map<string , int> wordOccurrence = tallyWords(inputFile);

  for (auto iter = wordOccurrence.cbegin(); iter != wordOccurrence.cend(); iter++) {
    cout << iter->first << " " << iter->second << endl;
  }


  return 0;
}
