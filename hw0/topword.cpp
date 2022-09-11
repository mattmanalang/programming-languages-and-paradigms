#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
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

void checkInputFile(ifstream& file) {
  if(!file.is_open()) {
    cout << "Error opening input file" << endl;
    exit(1);
  }
}

void checkOutputFile(ofstream& file) {
  if(!file.is_open()) {
    cout << "Error opening output file" << endl;
    exit(1);
  }
}

bool isOnlyLetters(string word) {
  for (char character : word) { // Loops through a word to see if all of it's contents are letters, and not numbers
    if (!isalpha(character)) {
      return false;
    }
  }
  return true;
}

string convertDelimitersToSpace(string text) {
  string converted(text);
  for (char& character : converted) { // Loops through the entire line of text and changes any non-alphanumeric characters to a white space for easier processing
    if (!isalnum(character))
      character = ' ';
  }
  return converted;
}

string convertToLowercase(string word) {
  string lowercaseWord = word;
  for_each(lowercaseWord.begin(), lowercaseWord.end(), [](char& character) { // Loops through the string, or word in this case, and converts it's characters to lowercase
    character = tolower(character);
  });
  return lowercaseWord;
}

void processLine(map<string, int>& wordCountTable, string text) {
  stringstream convertedText(convertDelimitersToSpace(text));
  string singleWord;

  while (convertedText >> singleWord) { // Loops, getting words from a string stream to be analyzed and counted
    if (!isOnlyLetters(singleWord))
      continue;
    wordCountTable[convertToLowercase(singleWord)]++;
  }
}

map<string, int> tallyWords(ifstream& inputFile) {
  map<string, int> wordCountTable;
  string textLine;

  while (getline(inputFile, textLine)) { // Loops through the file, getting each line
    processLine(wordCountTable, textLine);
  }
  return wordCountTable;
}

map<string, int> processFile(string fileName) {
  ifstream inputFile(fileName); // Input file may contain thousands of lines and even more words. Potentially up to the limits of the computer's memory
  checkInputFile(inputFile);

  auto result = tallyWords(inputFile);
  inputFile.close();
  return result;
}

int findHighestOccurrence(map<string, int> wordCountTable) {
  int maximumOccurrence = 0;
  for (pair<string, int> element : wordCountTable) { // Linear search through all entries in the map to find the highest value
    if (element.second > maximumOccurrence)
      maximumOccurrence = element.second;
  }
  return maximumOccurrence;
}

void outputTopWords(map<string, int> wordCountTable, string outputFileName) {
  int highestCount = findHighestOccurrence(wordCountTable);
  ofstream outputFile(outputFileName);
  checkOutputFile(outputFile);
  for (pair<string, int> element : wordCountTable) { // Loops through each pair in the map and outputs to file the ones that match the highest count
    if (element.second == highestCount) {
      outputFile << element.first << " " << element.second << endl;
    }
  }
  outputFile.close(); // Unlike the input file, the output file is going to tend to be MUCH smaller since it only contains the word(s) with the highest frequency.
}

int main(int argc, char const *argv[])
{
  checkNumberOfArgs(argc);
  ArgumentManager argManager(argc, argv);
  const string inputFileName(argManager.get("input"));
  const string outputFileName(argManager.get("output"));

  map<string , int, less<string>> wordOccurrence(processFile(inputFileName)); // less<string> sorts the map by the key (a string) in ascending order during creation
  outputTopWords(wordOccurrence, outputFileName);

  return 0;
}
