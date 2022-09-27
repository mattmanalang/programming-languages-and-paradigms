from ast import arg
import sys # Used for reading in the command-line arguments

def processLine(line):
  print(line.strip())

# Recursive method of reading through the file
def processFile(inFile):
  lineRead = inFile.readline()
  if (lineRead == ""):
    print("Line read was empty")
    return
  processLine(lineRead)
  processFile(inFile)

# Testing command: python freqnumber.py 'k=1;input=tc1.txt;output=freqnums.txt'
commandArgs = sys.argv[1].split(';') # Splits the argument string into the different parts
print(commandArgs)
test = list(map(lambda argument: argument.split('='), commandArgs)) # Returns a list/map from the first round of finding the arguments
argIter = iter(test)
print(next(argIter)[1])