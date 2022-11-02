#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// This minipython interpreter will be run by executing ./minipython python-file-name.py

using namespace std;

void checkNumberOfArgs(int argc) {
  if (argc == 1) {
    cout << "Error: No arguments were passed. Please provide an argument for input and output files." << endl;
    exit(1);
  }
}

int main(int argc, char const *argv[]) {
  // Check args
  checkNumberOfArgs(argc);
  const string pythonFileName = argv[1]; // Get the filename that was passed in
  
  auto loadFile = [](string fileName) { // Lambda function to load the contents of the python file into a vector
    ifstream pythonFile(fileName);
    vector<string> instructions;
    string line;
    while (getline(pythonFile, line)) {
      instructions.push_back(line);
    }
    pythonFile.close();
    return instructions;
  };

  vector<string> pyInstructions = loadFile(pythonFileName);
  for (string line : pyInstructions) {
    cout << line[3] << endl;
  }
  
  return 0;
}
