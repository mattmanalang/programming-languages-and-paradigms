#include <stdio.h>
#include <iostream>
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
  const string pythonFile = argv[1]; // Get the filename that was passed in

  // Driver code
  cout << pythonFile << endl;
}
