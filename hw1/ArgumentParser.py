# Module for parsing the command line arguments that were passed to the program
import sys

POS_IN_ARGV = 1

def checkNumberOfArgs(argv):
  if (len(argv) == 1): # Only the program name was passed
    sys.exit("Error: No arguments were passed. Please provide the specified arguments for k, input, and output")

def parseArgs(keyValuedArgs, targetArg, pos): # Recursive function that parses the arguments for the targetArg
  if (pos >= len(keyValuedArgs)): # If the argument specified was not found, error and exit.
    sys.exit("Error: \"{}\" argument not found. Please check command line arguments for correctness.".format(targetArg))
  if (keyValuedArgs[pos][0] == targetArg):
    return keyValuedArgs[pos][1]
  return parseArgs(keyValuedArgs, targetArg, pos+1)

def get(rawCommandArgs, targetArg): # Delegates the parsing to the parseArgs() function
  keyValuedArgs = list(map(lambda argument: argument.split('='), rawCommandArgs.split(';')))
  return parseArgs(keyValuedArgs, targetArg, 0)
